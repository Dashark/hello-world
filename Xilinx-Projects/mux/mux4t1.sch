<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="a(3:0)" />
        <signal name="a(0)" />
        <signal name="b(0)" />
        <signal name="a(1)" />
        <signal name="b(1)" />
        <signal name="a(2)" />
        <signal name="b(2)" />
        <signal name="a(3)" />
        <signal name="b(3)" />
        <signal name="sel" />
        <signal name="o(0)" />
        <signal name="o(1)" />
        <signal name="o(2)" />
        <signal name="o(3)" />
        <signal name="b(3:0)" />
        <signal name="o(3:0)" />
        <port polarity="Input" name="a(3:0)" />
        <port polarity="Input" name="sel" />
        <port polarity="Input" name="b(3:0)" />
        <port polarity="Output" name="o(3:0)" />
        <blockdef name="mux2t1">
            <timestamp>2018-5-18T8:33:19</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
        </blockdef>
        <block symbolname="mux2t1" name="XLXI_1">
            <blockpin signalname="a(0)" name="a" />
            <blockpin signalname="sel" name="sel" />
            <blockpin signalname="b(0)" name="b" />
            <blockpin signalname="o(0)" name="o" />
        </block>
        <block symbolname="mux2t1" name="XLXI_2">
            <blockpin signalname="a(1)" name="a" />
            <blockpin signalname="sel" name="sel" />
            <blockpin signalname="b(1)" name="b" />
            <blockpin signalname="o(1)" name="o" />
        </block>
        <block symbolname="mux2t1" name="XLXI_3">
            <blockpin signalname="a(2)" name="a" />
            <blockpin signalname="sel" name="sel" />
            <blockpin signalname="b(2)" name="b" />
            <blockpin signalname="o(2)" name="o" />
        </block>
        <block symbolname="mux2t1" name="XLXI_5">
            <blockpin signalname="a(3)" name="a" />
            <blockpin signalname="sel" name="sel" />
            <blockpin signalname="b(3)" name="b" />
            <blockpin signalname="o(3)" name="o" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1008" y="672" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1008" y="992" name="XLXI_2" orien="R0">
        </instance>
        <instance x="1008" y="1296" name="XLXI_3" orien="R0">
        </instance>
        <instance x="1008" y="1616" name="XLXI_5" orien="R0">
        </instance>
        <branch name="a(3:0)">
            <wire x2="640" y1="1008" y2="1008" x1="592" />
            <wire x2="640" y1="1008" y2="1136" x1="640" />
            <wire x2="640" y1="1136" y2="1232" x1="640" />
            <wire x2="640" y1="1232" y2="1424" x1="640" />
            <wire x2="640" y1="1424" y2="1440" x1="640" />
            <wire x2="640" y1="480" y2="496" x1="640" />
            <wire x2="640" y1="496" y2="672" x1="640" />
            <wire x2="640" y1="672" y2="704" x1="640" />
            <wire x2="640" y1="704" y2="832" x1="640" />
            <wire x2="640" y1="832" y2="896" x1="640" />
            <wire x2="640" y1="896" y2="1008" x1="640" />
        </branch>
        <iomarker fontsize="28" x="864" y="448" name="sel" orien="R270" />
        <iomarker fontsize="28" x="592" y="1008" name="a(3:0)" orien="R180" />
        <bustap x2="736" y1="496" y2="496" x1="640" />
        <bustap x2="736" y1="832" y2="832" x1="640" />
        <bustap x2="736" y1="1136" y2="1136" x1="640" />
        <bustap x2="736" y1="1424" y2="1424" x1="640" />
        <branch name="a(3)">
            <attrtext style="alignment:SOFT-TCENTER;fontsize:28;fontname:Arial" attrname="Name" x="976" y="1456" type="branch" />
            <wire x2="976" y1="1424" y2="1424" x1="736" />
            <wire x2="976" y1="1424" y2="1456" x1="976" />
            <wire x2="1008" y1="1456" y2="1456" x1="976" />
        </branch>
        <branch name="b(3)">
            <attrtext style="alignment:SOFT-TCENTER;fontsize:28;fontname:Arial" attrname="Name" x="976" y="1584" type="branch" />
            <wire x2="976" y1="1552" y2="1552" x1="496" />
            <wire x2="976" y1="1552" y2="1584" x1="976" />
            <wire x2="1008" y1="1584" y2="1584" x1="976" />
        </branch>
        <branch name="sel">
            <wire x2="864" y1="448" y2="576" x1="864" />
            <wire x2="976" y1="576" y2="576" x1="864" />
            <wire x2="1008" y1="576" y2="576" x1="976" />
            <wire x2="864" y1="576" y2="896" x1="864" />
            <wire x2="976" y1="896" y2="896" x1="864" />
            <wire x2="1008" y1="896" y2="896" x1="976" />
            <wire x2="864" y1="896" y2="1200" x1="864" />
            <wire x2="864" y1="1200" y2="1520" x1="864" />
            <wire x2="976" y1="1520" y2="1520" x1="864" />
            <wire x2="1008" y1="1520" y2="1520" x1="976" />
            <wire x2="976" y1="1200" y2="1200" x1="864" />
            <wire x2="1008" y1="1200" y2="1200" x1="976" />
        </branch>
        <branch name="o(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1424" y="512" type="branch" />
            <wire x2="1424" y1="512" y2="512" x1="1392" />
            <wire x2="1424" y1="512" y2="528" x1="1424" />
            <wire x2="1584" y1="528" y2="528" x1="1424" />
        </branch>
        <branch name="o(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1424" y="832" type="branch" />
            <wire x2="1424" y1="832" y2="832" x1="1392" />
            <wire x2="1584" y1="832" y2="832" x1="1424" />
        </branch>
        <branch name="o(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1424" y="1136" type="branch" />
            <wire x2="1424" y1="1136" y2="1136" x1="1392" />
            <wire x2="1584" y1="1136" y2="1136" x1="1424" />
        </branch>
        <branch name="o(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1424" y="1456" type="branch" />
            <wire x2="1424" y1="1456" y2="1456" x1="1392" />
            <wire x2="1584" y1="1456" y2="1456" x1="1424" />
        </branch>
        <branch name="b(3:0)">
            <wire x2="400" y1="1040" y2="1040" x1="320" />
            <wire x2="400" y1="1040" y2="1216" x1="400" />
            <wire x2="400" y1="1216" y2="1552" x1="400" />
            <wire x2="400" y1="1552" y2="1568" x1="400" />
            <wire x2="400" y1="640" y2="656" x1="400" />
            <wire x2="400" y1="656" y2="912" x1="400" />
            <wire x2="400" y1="912" y2="1040" x1="400" />
        </branch>
        <iomarker fontsize="28" x="320" y="1040" name="b(3:0)" orien="R180" />
        <bustap x2="496" y1="656" y2="656" x1="400" />
        <bustap x2="496" y1="912" y2="912" x1="400" />
        <bustap x2="496" y1="1216" y2="1216" x1="400" />
        <bustap x2="496" y1="1552" y2="1552" x1="400" />
        <branch name="o(3:0)">
            <wire x2="1680" y1="512" y2="528" x1="1680" />
            <wire x2="1680" y1="528" y2="832" x1="1680" />
            <wire x2="1680" y1="832" y2="960" x1="1680" />
            <wire x2="1760" y1="960" y2="960" x1="1680" />
            <wire x2="1680" y1="960" y2="1136" x1="1680" />
            <wire x2="1680" y1="1136" y2="1456" x1="1680" />
        </branch>
        <iomarker fontsize="28" x="1760" y="960" name="o(3:0)" orien="R0" />
        <bustap x2="1584" y1="528" y2="528" x1="1680" />
        <bustap x2="1584" y1="832" y2="832" x1="1680" />
        <bustap x2="1584" y1="1136" y2="1136" x1="1680" />
        <bustap x2="1584" y1="1456" y2="1456" x1="1680" />
        <branch name="a(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="976" y="1136" type="branch" />
            <wire x2="976" y1="1136" y2="1136" x1="736" />
            <wire x2="1008" y1="1136" y2="1136" x1="976" />
        </branch>
        <branch name="b(2)">
            <attrtext style="alignment:SOFT-TCENTER;fontsize:28;fontname:Arial" attrname="Name" x="976" y="1264" type="branch" />
            <wire x2="976" y1="1216" y2="1216" x1="496" />
            <wire x2="976" y1="1216" y2="1264" x1="976" />
            <wire x2="1008" y1="1264" y2="1264" x1="976" />
        </branch>
        <branch name="a(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="976" y="832" type="branch" />
            <wire x2="976" y1="832" y2="832" x1="736" />
            <wire x2="1008" y1="832" y2="832" x1="976" />
        </branch>
        <branch name="b(1)">
            <attrtext style="alignment:SOFT-TCENTER;fontsize:28;fontname:Arial" attrname="Name" x="976" y="960" type="branch" />
            <wire x2="976" y1="912" y2="912" x1="496" />
            <wire x2="976" y1="912" y2="960" x1="976" />
            <wire x2="1008" y1="960" y2="960" x1="976" />
        </branch>
        <branch name="a(0)">
            <attrtext style="alignment:SOFT-TCENTER;fontsize:28;fontname:Arial" attrname="Name" x="976" y="512" type="branch" />
            <wire x2="976" y1="496" y2="496" x1="736" />
            <wire x2="976" y1="496" y2="512" x1="976" />
            <wire x2="1008" y1="512" y2="512" x1="976" />
        </branch>
        <branch name="b(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="976" y="640" type="branch" />
            <wire x2="976" y1="656" y2="656" x1="496" />
            <wire x2="1008" y1="640" y2="640" x1="976" />
            <wire x2="976" y1="640" y2="656" x1="976" />
        </branch>
    </sheet>
</drawing>