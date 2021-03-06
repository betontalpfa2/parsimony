package main;


import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.TerminalNodeImpl;

import verilog.Direction;
import verilog.ParameterDescriptior;
import verilog.PrimitiveDescriptor;
import verilog.Type;
import antlr.Verilog2001BaseListener;
import antlr.Verilog2001Parser;
import antlr.Verilog2001Parser.Module_itemContext;
import antlr.Verilog2001Parser.Module_parameter_port_listContext;
import antlr.Verilog2001Parser.Param_assignmentContext;
import antlr.Verilog2001Parser.Parameter_declarationContext;
import antlr.Verilog2001Parser.Parameter_declaration_Context;
import antlr.Verilog2001Parser.PortContext;
import antlr.Verilog2001Parser.Port_declarationContext;
import antlr.Verilog2001Parser.Port_identifierContext;
import antlr.Verilog2001Parser.PrimaryContext;
import antlr.Verilog2001Parser.RangeContext;
import antlr.Verilog2001Parser.TermContext;

/**
 * Direction is an enum to store ports direction of modules.
 * 
 * @author Benedek Racz
 *
 */

/**
 * PrimitiveMapper is a class to parsing verilog simulation primitives.
 * 
 * @author Benedek Racz
 *
 */
public class PrimitiveMapper extends Verilog2001BaseListener {
	final boolean verbose = true;
	static List<PrimitiveDescriptor> primitiveDEclarationList = Collections.synchronizedList( new ArrayList<PrimitiveDescriptor>());
	String filename;
	
	/**
	 * ANTLR call enterModule_declaration() when a new module declaration starts.
	 * Ex.: module MY_MODULE (clk, reset)
	 * 		... 
	 */
    @Override
    public void enterModule_declaration(Verilog2001Parser.Module_declarationContext ctx) {
    	PrimitiveDescriptor primitiveDeclaration = new PrimitiveDescriptor();
    	
    	if(ctx.attribute_instance().size()>0){
    		Logger.writeError("Attribute instance is not suppoerted at module declaration.");
    		return;
    	}
    	
    	/**
    	 * Handle the module identifier (the name of this module)
    	 */
    	String moduleId = null;
    	try{
    		moduleId = ctx.module_identifier().getText();
    	} catch(NullPointerException ex){
    		ex.printStackTrace();
    		Logger.writeError("at line: " + ctx.start.getLine() + " " + ctx.getStart().getInputStream().getSourceName() + " " + Thread.currentThread().getName());
    		return;
    	}
    	primitiveDeclaration.setPrimitiveIdentifier(moduleId);
    	
    	/**
    	 * Handle the module parameters aka. generics
    	 */
    	Module_parameter_port_listContext parameterList = ctx.module_parameter_port_list();
    	try{
    	for (Parameter_declaration_Context parameter : parameterList.parameter_declaration_()){
    		for(Param_assignmentContext parameterAssignments : parameter.list_of_param_assignments().param_assignment()){
    			String parameterName = parameterAssignments.parameter_identifier().getText();
    			String parameterValue = parameterAssignments.constant_expression().getText();
    			
    			primitiveDeclaration.addParameter(parameterName, Type.UNDEFINED, parameterValue);
    		}
    	}
    	}catch(NullPointerException ex){
    		if(verbose){
    			Logger.writeInfo("There is no parameter in this module...");
    		}
    	}
    	
    	/**
    	 * Handle port declaration.
    	 * There are several type of declaring ports. Now only one method is
    	 * supported. See below.
    	 */
    	if(ctx.list_of_port_declarations() != null){
    		Logger.writeError("list of port declarations is not suppoerted at module declaration.");
    		return;    		
    	}
    	try{
	    	for(PortContext port: ctx.list_of_ports().port()){
	    		// This seems a bug...
	//    		for(int i = 0 ; i< port.getChildCount(); i++){
	//    			ParseTree child = port.getChild(i);
	//        		System.out.println("type: " + child.getClass() + "  Text: " + child.getText());
	//    		}
	    		
	    		primitiveDeclaration.addPort(port.getText());
	    	}
    	} catch(NullPointerException ex){
    		Logger.writeWarning("Null pointer exeption while parsing module: " + moduleId + " at line: " + ctx.start.getLine());
    	}
    	
    	/**
    	 * Handle the module body.
    	 * The port direction can be parse here, and more module parameters aka.
    	 * generics.
    	 */
    	for (Module_itemContext moduleItem : ctx.module_item()){

    		/**
    		 * Investigate parameter:
    		 */
    		Parameter_declarationContext parameterDeclaration = moduleItem.parameter_declaration();
    		if(null != parameterDeclaration){
	        	Parameter_declaration_Context parameter = parameterDeclaration.parameter_declaration_();
	    		for(Param_assignmentContext parameterAssignments : parameter.list_of_param_assignments().param_assignment()){
	    			String parameterName = parameterAssignments.parameter_identifier().getText();
	    			if(1 != parameterAssignments.constant_expression().expression().getChildCount()){
	    				Logger.writeError("Exactely one child is suppoerted at parameter assignments.\n\tModule: " + moduleId + "  parameter: " + parameterName + "  Child count: " + parameterAssignments.constant_expression().expression().getChildCount());
	    	    		return;
	    			}
	    			ParseTree child = parameterAssignments.constant_expression().expression().getChild(0);
	    			if(! (child instanceof TermContext) ){
	    	    		Logger.writeError("Child is not instanceof TermContext at parameter assignments.\n\tModule: " + moduleId + "  parameter: " + parameterName + "  Child count: " + parameterAssignments.constant_expression().expression().getChildCount());
	    	    		return;
	    			}
	    			
	    			TermContext termContext = (TermContext) child;
	    			
	    			if(1 != termContext.getChildCount()){
	    				Logger.writeError("Exactely one child is suppoerted at parameter assignments term context.\n\tModule: " + moduleId + "  parameter: " + parameterName + "  Child count: " + termContext.getChildCount());
	    	    		return;
	    			}
	    			
    				ParseTree termContextChild = termContext.getChild(0);
    				Logger.writeInfo("module: " + moduleId + "  parameter: " + parameterName + "  childType: " + termContextChild.getClass() + "  childText: " + termContextChild.getText());
	    			
	    			
	    			String parameterValue = parameterAssignments.constant_expression().getText();
	    			
	    			if(! parameterValue.equals("\"UNPLACED\"")){
	    				System.out.println("hello");
	    			}
	    			
	    			Type parameterType = Type.UNDEFINED;
	    			
	    			if (termContextChild instanceof TerminalNodeImpl){
	    				parameterType = Type.PARAMETER_STRING_T;
	    				if(ParameterDescriptior.isEnum(parameterValue)){
		    				parameterType = Type.PARAMETER_ENUM_T;
	    				}
	    			}
	    			
	    			if (termContextChild instanceof PrimaryContext){
	    				parameterType = Type.PARAMETER_INT_T;
	    			}
	    			
	    			
	    			primitiveDeclaration.addParameter(parameterName, parameterType, parameterValue);
	    		}
	    		continue;
    		}
    		
    		if(moduleId.equals("X_CARRY4")){
    			System.out.println("Debug");
    		}
    		
    		/**
    		 * Investigate port:
    		 * Distinguish below in/out/inout port.
    		 */
    		Port_declarationContext portDeclaration = moduleItem.port_declaration();
    		if(null != portDeclaration){
    			List<Port_identifierContext> portIdList;
    			RangeContext range = null;
    			
    			try{
    				//The following line throws null pointer if the port is not input port
    				portIdList = portDeclaration.input_declaration().list_of_port_identifiers().port_identifier();
    				range = portDeclaration.input_declaration().range();
		    		for(Port_identifierContext portId : portIdList){
		    			primitiveDeclaration.updatePort(portId.getText(), Direction.INPUT, range);
			    		continue;
		    		}
    			}catch(NullPointerException ex){} //The port is not input port...

    			try{
    				portIdList = portDeclaration.output_declaration().list_of_port_identifiers().port_identifier();
    				range = portDeclaration.output_declaration().range();
		    		for(Port_identifierContext portId : portIdList){
		    			primitiveDeclaration.updatePort(portId.getText(), Direction.OUTPUT, range);
			    		continue;
	    			}
    			}catch(NullPointerException ex){}

    			try{
    				portIdList = portDeclaration.inout_declaration().list_of_port_identifiers().port_identifier();
    				range = portDeclaration.output_declaration().range();
		    		for(Port_identifierContext portId : portDeclaration.inout_declaration().list_of_port_identifiers().port_identifier()){
		    			primitiveDeclaration.updatePort(portId.getText(), Direction.INOUT, range);
			    		continue;
	    			}
    			}catch(NullPointerException ex){}
	    		continue;
    		}
        }
    	
    	primitiveDEclarationList.add(primitiveDeclaration);
    }

    /**
     * This is a simple (debug) function which prints the loaded/parsed data of
     * primitives. It prints identifier, ports, parameters.
     */
	public static void printResults() {
		for(PrimitiveDescriptor primitive : primitiveDEclarationList){
			primitive.printInfo();
		}
		
	}
	
	/**
	 * Save data of parsed primitives (aka. primitiveDEclarationList) to file.
	 * It use the serialization Java interface.
	 */
	public static void saveData(){
		try
	      {
			String saveFileName = "primitives.ser";
	        FileOutputStream fileOut = new FileOutputStream(saveFileName);
	        ObjectOutputStream out = new ObjectOutputStream(fileOut);
	        ArrayList<PrimitiveDescriptor> copyList = new ArrayList<PrimitiveDescriptor>(primitiveDEclarationList);
//	        
	        out.writeObject(copyList);
	        out.close();
	        fileOut.close();
	        Logger.writeInfo("Serialized data is saved in " + saveFileName);
	      }catch(IOException i)
	      {
	          i.printStackTrace();
	      }
	   }
		
	/**
	 * It loads data of primitives (aka. primitiveDEclarationList) from file.
	 * It use the serialization Java interface.
	 */
	public static boolean loadData(){
		primitiveDEclarationList = new ArrayList<PrimitiveDescriptor>();
		try {
			String saveFileName = "primitives.ser";
	        FileInputStream fileIn = new FileInputStream(saveFileName);
	        ObjectInputStream in = new ObjectInputStream(fileIn);
	        Object readedObj = in.readObject();
	        //primitiveDEclarationList = (List<PrimitiveDescriptor>) in.readObject();
	        
	        // Check it's an ArrayList
	        if (readedObj instanceof ArrayList<?>) {
	        	// Get the List.
	        	ArrayList<?> al = (ArrayList<?>) readedObj;
	        	if (al.size() > 0) {
	        		// Iterate.
	        		for (int i = 0; i < al.size(); i++) {
	        			// Still not enough for a type.
	        			Object o = al.get(i);
	        			if (o instanceof PrimitiveDescriptor) {
	        				// Here we go!
	        				PrimitiveDescriptor v = (PrimitiveDescriptor) o;
	        				// use v.
	        				
	        				primitiveDEclarationList.add(v);
	        			}
	        			else{
	        				Logger.writeError("o is not instanceof PrimitiveDescriptor");
	        			}
	        		}
	        	}
	        }
    		else{
    			Logger.writeError("o is not instanceof array");
    		}
	        
	        in.close();
	        fileIn.close();
	      }catch(IOException i)
	      {
	         i.printStackTrace();
	         return false;
	      }catch(ClassNotFoundException c)
	      {
	    	 Logger.writeError("Class not found");
	         c.printStackTrace();
	         return false;
	      }
		Logger.writeInfo("Load Success?");
		return true;
	}

}
