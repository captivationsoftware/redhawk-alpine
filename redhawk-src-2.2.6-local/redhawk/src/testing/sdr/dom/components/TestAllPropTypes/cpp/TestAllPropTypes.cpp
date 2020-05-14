/*
 * This file is protected by Copyright. Please refer to the COPYRIGHT file 
 * distributed with this source distribution.
 * 
 * This file is part of REDHAWK core.
 * 
 * REDHAWK core is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU Lesser General Public License as published by the 
 * Free Software Foundation, either version 3 of the License, or (at your 
 * option) any later version.
 * 
 * REDHAWK core is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License 
 * for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */


/**************************************************************************

    This is the component code. This file contains the child class where
    custom functionality can be added to the component. Custom
    functionality to the base class can be extended here. Access to
    the ports can also be done from this class

 	Source: TestAllPropTypes.spd.xml
 	Generated on: Tue May 07 10:59:08 EDT 2013
 	REDHAWK IDE
 	Version: R.1.8.3
 	Build id: v201303122306

**************************************************************************/

#include "TestAllPropTypes.h"

PREPARE_LOGGING(TestAllPropTypes_i)

TestAllPropTypes_i::TestAllPropTypes_i(const char *uuid, const char *label) : 
    TestAllPropTypes_base(uuid, label)
{
    setPropertyChangeListener("simple_string", this, &TestAllPropTypes_i::simpleStringChanged);
    setPropertyChangeListener("simple_boolean", this, &TestAllPropTypes_i::simpleBooleanChanged);
    setPropertyChangeListener("simple_ulong", this, &TestAllPropTypes_i::simpleULongChanged);
    setPropertyChangeListener("simple_objref", this, &TestAllPropTypes_i::simpleObjRefChanged);
    setPropertyChangeListener("simple_short", this, &TestAllPropTypes_i::simpleShortChanged);
    setPropertyChangeListener("simple_float", this, &TestAllPropTypes_i::simpleFloatChanged);
    setPropertyChangeListener("simple_octet", this, &TestAllPropTypes_i::simpleOctetChanged);
    setPropertyChangeListener("simple_char", this, &TestAllPropTypes_i::simpleCharChanged);
    setPropertyChangeListener("simple_ushort", this, &TestAllPropTypes_i::simpleUShortChanged);
    setPropertyChangeListener("simple_double", this, &TestAllPropTypes_i::simpleDoubleChanged);
    setPropertyChangeListener("simple_long", this, &TestAllPropTypes_i::simpleLongChanged);
    setPropertyChangeListener("simple_longlong", this, &TestAllPropTypes_i::simpleLongLongChanged);
    setPropertyChangeListener("simple_ulonglong", this, &TestAllPropTypes_i::simpleULongLongChanged);
    setPropertyChangeListener("simple_sequence_string", this, &TestAllPropTypes_i::seqStringChanged);
    setPropertyChangeListener("simple_sequence_boolean", this, &TestAllPropTypes_i::seqBooleanChanged);
    setPropertyChangeListener("simple_sequence_ulong", this, &TestAllPropTypes_i::seqULongChanged);
    setPropertyChangeListener("simple_sequence_objref", this, &TestAllPropTypes_i::seqObjRefChanged);
    setPropertyChangeListener("simple_sequence_short", this, &TestAllPropTypes_i::seqShortChanged);
    setPropertyChangeListener("simple_sequence_float", this, &TestAllPropTypes_i::seqFloatChanged);
    setPropertyChangeListener("simple_sequence_octet", this, &TestAllPropTypes_i::seqOctetChanged);
    setPropertyChangeListener("simple_sequence_char", this, &TestAllPropTypes_i::seqCharChanged);
    setPropertyChangeListener("simple_sequence_ushort", this, &TestAllPropTypes_i::seqUShortChanged);
    setPropertyChangeListener("simple_sequence_double", this, &TestAllPropTypes_i::seqDoubleChanged);
    setPropertyChangeListener("simple_sequence_long", this, &TestAllPropTypes_i::seqLongChanged);
    setPropertyChangeListener("simple_sequence_longlong", this, &TestAllPropTypes_i::seqLongLongChanged);
    setPropertyChangeListener("simple_sequence_ulonglong", this, &TestAllPropTypes_i::seqULongLongChanged);
    setPropertyChangeListener("struct_vars", this, &TestAllPropTypes_i::structChanged);
    setPropertyChangeListener("struct_seq", this, &TestAllPropTypes_i::structSeqChanged);
}

TestAllPropTypes_i::~TestAllPropTypes_i()
{
}


/***********************************************************************************************

    Basic functionality:

        The service function is called by the serviceThread object (of type ProcessThread).
        This call happens immediately after the previous call if the return value for
        the previous call was NORMAL.
        If the return value for the previous call was NOOP, then the serviceThread waits
        an amount of time defined in the serviceThread's constructor.
        
    SRI:
        To create a StreamSRI object, use the following code:
        	stream_id = "";
	    	sri = BULKIO::StreamSRI();
	    	sri.hversion = 1;
	    	sri.xstart = 0.0;
	    	sri.xdelta = 0.0;
	    	sri.xunits = BULKIO::UNITS_TIME;
	    	sri.subsize = 0;
	    	sri.ystart = 0.0;
	    	sri.ydelta = 0.0;
	    	sri.yunits = BULKIO::UNITS_NONE;
	    	sri.mode = 0;
	    	sri.streamID = this->stream_id.c_str();

	Time:
	    To create a PrecisionUTCTime object, use the following code:
	        struct timeval tmp_time;
	        struct timezone tmp_tz;
	        gettimeofday(&tmp_time, &tmp_tz);
	        double wsec = tmp_time.tv_sec;
	        double fsec = tmp_time.tv_usec / 1e6;;
	        BULKIO::PrecisionUTCTime tstamp = BULKIO::PrecisionUTCTime();
	        tstamp.tcmode = BULKIO::TCM_CPU;
	        tstamp.tcstatus = (short)1;
	        tstamp.toff = 0.0;
	        tstamp.twsec = wsec;
	        tstamp.tfsec = fsec;
        
    Ports:

        Data is passed to the serviceFunction through the getPacket call (BULKIO only).
        The dataTransfer class is a port-specific class, so each port implementing the
        BULKIO interface will have its own type-specific dataTransfer.

        The argument to the getPacket function is a floating point number that specifies
        the time to wait in seconds. A zero value is non-blocking. A negative value
        is blocking.

        Each received dataTransfer is owned by serviceFunction and *MUST* be
        explicitly deallocated.

        To send data using a BULKIO interface, a convenience interface has been added 
        that takes a std::vector as the data input

        NOTE: If you have a BULKIO dataSDDS port, you must manually call 
              "port->updateStats()" to update the port statistics when appropriate.

        Example:
            // this example assumes that the component has two ports:
            //  A provides (input) port of type BULKIO::dataShort called short_in
            //  A uses (output) port of type BULKIO::dataFloat called float_out
            // The mapping between the port and the class is found
            // in the component base class header file

            BULKIO_dataShort_In_i::dataTransfer *tmp = short_in->getPacket(-1);
            if (not tmp) { // No data is available
                return NOOP;
            }

            std::vector<float> outputData;
            outputData.resize(tmp->dataBuffer.size());
            for (unsigned int i=0; i<tmp->dataBuffer.size(); i++) {
                outputData[i] = (float)tmp->dataBuffer[i];
            }

            // NOTE: You must make at least one valid pushSRI call
            if (tmp->sriChanged) {
                float_out->pushSRI(tmp->SRI);
            }
            float_out->pushPacket(outputData, tmp->T, tmp->EOS, tmp->streamID);

            delete tmp; // IMPORTANT: MUST RELEASE THE RECEIVED DATA BLOCK
            return NORMAL;

        Interactions with non-BULKIO ports are left up to the component developer's discretion

    Properties:
        
        Properties are accessed directly as member variables. For example, if the
        property name is "baudRate", it may be accessed within member functions as
        "baudRate". Unnamed properties are given a generated name of the form
        "prop_n", where "n" is the ordinal number of the property in the PRF file.
        Property types are mapped to the nearest C++ type, (e.g. "string" becomes
        "std::string"). All generated properties are declared in the base class
        (TestAllPropTypes_base).
    
        Simple sequence properties are mapped to "std::vector" of the simple type.
        Struct properties, if used, are mapped to C++ structs defined in the
        generated file "struct_props.h". Field names are taken from the name in
        the properties file; if no name is given, a generated name of the form
        "field_n" is used, where "n" is the ordinal number of the field.
        
        Example:
            // This example makes use of the following Properties:
            //  - A float value called scaleValue
            //  - A boolean called scaleInput
              
            if (scaleInput) {
                dataOut[i] = dataIn[i] * scaleValue;
            } else {
                dataOut[i] = dataIn[i];
            }
            
        A callback method can be associated with a property so that the method is
        called each time the property value changes.  This is done by calling 
        setPropertyChangeListener(<property name>, this, &TestAllPropTypes::<callback method>)
        in the constructor.
            
        Example:
            // This example makes use of the following Properties:
            //  - A float value called scaleValue
            
        //Add to TestAllPropTypes.cpp
        TestAllPropTypes_i::TestAllPropTypes_i(const char *uuid, const char *label) :
            TestAllPropTypes_base(uuid, label)
        {
            setPropertyChangeListener("scaleValue", this, &TestAllPropTypes_i::scaleChanged);
        }

        void TestAllPropTypes_i::scaleChanged(const std::string& id){
            std::cout << "scaleChanged scaleValue " << scaleValue << std::endl;
        }
            
        //Add to TestAllPropTypes.h
        void scaleChanged(const std::string&);
        
        
************************************************************************************************/
void TestAllPropTypes_i::simpleStringChanged(const std::string& id)
{
    this->simple_string = "42";
}

void TestAllPropTypes_i::simpleBooleanChanged(const std::string& id)
{
    this->simple_boolean = true;
}

void TestAllPropTypes_i::simpleULongChanged(const std::string& id)
{
    this->simple_ulong = 43;
}

void TestAllPropTypes_i::simpleObjRefChanged(const std::string& id)
{
    this->simple_objref = "44";
}

void TestAllPropTypes_i::simpleShortChanged(const std::string& id)
{
    this->simple_short = 45;
}

void TestAllPropTypes_i::simpleFloatChanged(const std::string& id)
{
    this->simple_float = 46.0;
}

void TestAllPropTypes_i::simpleOctetChanged(const std::string& id)
{
    this->simple_octet = 47;
}

void TestAllPropTypes_i::simpleCharChanged(const std::string& id)
{
    this->simple_char = 48;
}

void TestAllPropTypes_i::simpleUShortChanged(const std::string& id)
{
    this->simple_ushort = 49;
}

void TestAllPropTypes_i::simpleDoubleChanged(const std::string& id)
{
    this->simple_double = 50.0;
}

void TestAllPropTypes_i::simpleLongChanged(const std::string& id)
{
    this->simple_long = 51;
}

void TestAllPropTypes_i::simpleLongLongChanged(const std::string& id)
{
    this->simple_longlong = 52;
}

void TestAllPropTypes_i::simpleULongLongChanged(const std::string& id)
{
    this->simple_ulonglong = 53;
}

void TestAllPropTypes_i::seqStringChanged(const std::string& id)
{
    this->simple_sequence_string.clear();
    this->simple_sequence_string.push_back("54");
}

void TestAllPropTypes_i::seqBooleanChanged(const std::string& id)
{
    this->simple_sequence_boolean.clear();
    this->simple_sequence_boolean.push_back(true);
}

void TestAllPropTypes_i::seqULongChanged(const std::string& id)
{
    this->simple_sequence_ulong.clear();
    this->simple_sequence_ulong.push_back(55);
}

void TestAllPropTypes_i::seqObjRefChanged(const std::string& id)
{
    this->simple_sequence_objref.clear();
    this->simple_sequence_objref.push_back("56");
}

void TestAllPropTypes_i::seqShortChanged(const std::string& id)
{
    this->simple_sequence_short.clear();
    this->simple_sequence_short.push_back(57);
}

void TestAllPropTypes_i::seqFloatChanged(const std::string& id)
{
    this->simple_sequence_float.clear();
    this->simple_sequence_float.push_back(58.0);
}

void TestAllPropTypes_i::seqOctetChanged(const std::string& id)
{
    this->simple_sequence_octet.clear();
    this->simple_sequence_octet.push_back(59);
}

void TestAllPropTypes_i::seqCharChanged(const std::string& id)
{
    this->simple_sequence_char.clear();
    this->simple_sequence_char.push_back(60);
}

void TestAllPropTypes_i::seqUShortChanged(const std::string& id)
{
    this->simple_sequence_ushort.clear();
    this->simple_sequence_ushort.push_back(61);
}

void TestAllPropTypes_i::seqDoubleChanged(const std::string& id)
{
    this->simple_sequence_double.clear();
    this->simple_sequence_double.push_back(62.0);
}

void TestAllPropTypes_i::seqLongChanged(const std::string& id)
{
    this->simple_sequence_long.clear();
    this->simple_sequence_long.push_back(63);
}

void TestAllPropTypes_i::seqLongLongChanged(const std::string& id)
{
    this->simple_sequence_longlong.clear();
    this->simple_sequence_longlong.push_back(64);
}

void TestAllPropTypes_i::seqULongLongChanged(const std::string& id)
{
    this->simple_sequence_ulonglong.clear();
    this->simple_sequence_ulonglong.push_back(65);
}

void TestAllPropTypes_i::structChanged(const std::string& id)
{
    this->struct_vars.struct_string = "66";
}

void TestAllPropTypes_i::structSeqChanged(const std::string& id)
{
    this->struct_seq.clear();
    struct_seq_vars_struct temp;
    temp.struct_seq_string = "67";
    this->struct_seq.push_back(temp);
}

int TestAllPropTypes_i::serviceFunction()
{
    LOG_DEBUG(TestAllPropTypes_i, "serviceFunction() example log message");
    
    return NOOP;
}
