<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE softpkg PUBLIC "-//JTRS//DTD SCA V2.2.2 SPD//EN" "softpkg.dtd">
<softpkg id="DCE:ebb8b677-5519-4433-8053-37f735e6ff95" name="DevC" type="2.0.7">
  <title></title>
  <author>
    <name>null</name>
  </author>
  <propertyfile type="PRF">
    <localfile name="DevC.prf.xml"/>
  </propertyfile>
  <descriptor>
    <localfile name="DevC.scd.xml"/>
  </descriptor>
  <implementation id="java">
    <description>The implementation contains descriptive information about the template for a software resource.</description>
    <code type="Executable">
      <localfile name="java"/>
      <entrypoint>java/startJava.sh</entrypoint>
    </code>
    <compiler name="/usr/bin/javac" version="1.7"/>
    <programminglanguage name="Java"/>
    <humanlanguage name="EN"/>
    <runtime name="/usr/bin/java" version="1.7"/>
    <os name="Linux"/>
  </implementation>
</softpkg>
