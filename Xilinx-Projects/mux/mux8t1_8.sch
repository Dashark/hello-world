<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="x7(3:0)" />
        <signal name="x4(3:0)" />
        <signal name="x5(3:0)" />
        <signal name="x2(3:0)" />
        <signal name="x3(3:0)" />
        <signal name="x0(3:0)" />
        <signal name="x1(3:0)" />
        <signal name="x7(7:4)" />
        <signal name="x4(7:4)" />
        <signal name="x5(7:4)" />
        <signal name="x2(7:4)" />
        <signal name="x3(7:4)" />
        <signal name="x0(7:4)" />
        <signal name="x1(7:4)" />
        <signal name="o(7:4)" />
        <signal name="o(3:0)" />
        <signal name="x6(7:0)" />
        <signal name="x7(7:0)" />
        <signal name="x6(7:4)" />
        <signal name="x6(3:0)" />
        <signal name="x4(7:0)" />
        <signal name="x5(7:0)" />
        <signal name="x2(7:0)" />
        <signal name="x3(7:0)" />
        <signal name="x0(7:0)" />
        <signal name="x1(7:0)" />
        <signal name="o(7:0)" />
        <signal name="sel(2:0)" />
        <port polarity="Input" name="x6(7:0)" />
        <port polarity="Input" name="x7(7:0)" />
        <port polarity="Input" name="x4(7:0)" />
        <port polarity="Input" name="x5(7:0)" />
        <port polarity="Input" name="x2(7:0)" />
        <port polarity="Input" name="x3(7:0)" />
        <port polarity="Input" name="x0(7:0)" />
        <port polarity="Input" name="x1(7:0)" />
        <port polarity="Output" name="o(7:0)" />
        <port polarity="Input" name="sel(2:0)" />
        <blockdef name="mux8t1">
            <timestamp>2018-5-18T9:12:2</timestamp>
            <rect width="256" x="64" y="-576" height="576" />
            <rect width="64" x="0" y="-556" height="24" />
            <line x2="0" y1="-544" y2="-544" x1="64" />
            <rect width="64" x="0" y="-492" height="24" />
            <line x2="0" y1="-480" y2="-480" x1="64" />
            <rect width="64" x="0" y="-428" height="24" />
            <line x2="0" y1="-416" y2="-416" x1="64" />
            <rect width="64" x="0" y="-364" height="24" />
            <line x2="0" y1="-352" y2="-352" x1="64" />
            <rect width="64" x="0" y="-300" height="24" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <rect width="64" x="0" y="-236" height="24" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-556" height="24" />
            <line x2="384" y1="-544" y2="-544" x1="320" />
        </blockdef>
        <block symbolname="mux8t1" name="XLXI_1">
            <blockpin signalname="x1(7:4)" name="x1(3:0)" />
            <blockpin signalname="x0(7:4)" name="x0(3:0)" />
            <blockpin signalname="x3(7:4)" name="x3(3:0)" />
            <blockpin signalname="x2(7:4)" name="x2(3:0)" />
            <blockpin signalname="x5(7:4)" name="x5(3:0)" />
            <blockpin signalname="x4(7:4)" name="x4(3:0)" />
            <blockpin signalname="x7(7:4)" name="x7(3:0)" />
            <blockpin signalname="x6(7:4)" name="x6(3:0)" />
            <blockpin signalname="sel(2:0)" name="sel(2:0)" />
            <blockpin signalname="o(7:4)" name="o(3:0)" />
        </block>
        <block symbolname="mux8t1" name="XLXI_2">
            <blockpin signalname="x1(3:0)" name="x1(3:0)" />
            <blockpin signalname="x0(3:0)" name="x0(3:0)" />
            <blockpin signalname="x3(3:0)" name="x3(3:0)" />
            <blockpin signalname="x2(3:0)" name="x2(3:0)" />
            <blockpin signalname="x5(3:0)" name="x5(3:0)" />
            <blockpin signalname="x4(3:0)" name="x4(3:0)" />
            <blockpin signalname="x7(3:0)" name="x7(3:0)" />
            <blockpin signalname="x6(3:0)" name="x6(3:0)" />
            <blockpin signalname="sel(2:0)" name="sel(2:0)" />
            <blockpin signalname="o(3:0)" name="o(3:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1920" y="1120" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1920" y="1776" name="XLXI_2" orien="R0">
        </instance>
        <branch name="x7(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="1616" type="branch" />
            <wire x2="1904" y1="1616" y2="1616" x1="1776" />
            <wire x2="1920" y1="1616" y2="1616" x1="1904" />
        </branch>
        <branch name="x4(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="1552" type="branch" />
            <wire x2="1904" y1="1552" y2="1552" x1="1664" />
            <wire x2="1920" y1="1552" y2="1552" x1="1904" />
        </branch>
        <branch name="x5(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="1488" type="branch" />
            <wire x2="1904" y1="1488" y2="1488" x1="1552" />
            <wire x2="1920" y1="1488" y2="1488" x1="1904" />
        </branch>
        <branch name="x2(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="1424" type="branch" />
            <wire x2="1904" y1="1424" y2="1424" x1="1440" />
            <wire x2="1920" y1="1424" y2="1424" x1="1904" />
        </branch>
        <branch name="x3(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="1360" type="branch" />
            <wire x2="1904" y1="1360" y2="1360" x1="1312" />
            <wire x2="1920" y1="1360" y2="1360" x1="1904" />
        </branch>
        <branch name="x0(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="1296" type="branch" />
            <wire x2="1904" y1="1296" y2="1296" x1="1200" />
            <wire x2="1920" y1="1296" y2="1296" x1="1904" />
        </branch>
        <branch name="x1(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="1232" type="branch" />
            <wire x2="1904" y1="1232" y2="1232" x1="1088" />
            <wire x2="1920" y1="1232" y2="1232" x1="1904" />
        </branch>
        <branch name="x7(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="960" type="branch" />
            <wire x2="1904" y1="960" y2="960" x1="1776" />
            <wire x2="1920" y1="960" y2="960" x1="1904" />
        </branch>
        <branch name="x4(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="896" type="branch" />
            <wire x2="1904" y1="896" y2="896" x1="1664" />
            <wire x2="1920" y1="896" y2="896" x1="1904" />
        </branch>
        <branch name="x5(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="832" type="branch" />
            <wire x2="1904" y1="832" y2="832" x1="1552" />
            <wire x2="1920" y1="832" y2="832" x1="1904" />
        </branch>
        <branch name="x2(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="768" type="branch" />
            <wire x2="1904" y1="768" y2="768" x1="1440" />
            <wire x2="1920" y1="768" y2="768" x1="1904" />
        </branch>
        <branch name="x3(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="704" type="branch" />
            <wire x2="1904" y1="704" y2="704" x1="1312" />
            <wire x2="1920" y1="704" y2="704" x1="1904" />
        </branch>
        <branch name="x0(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="640" type="branch" />
            <wire x2="1904" y1="640" y2="640" x1="1200" />
            <wire x2="1920" y1="640" y2="640" x1="1904" />
        </branch>
        <branch name="x1(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="576" type="branch" />
            <wire x2="1904" y1="576" y2="576" x1="1088" />
            <wire x2="1920" y1="576" y2="576" x1="1904" />
        </branch>
        <branch name="o(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2320" y="576" type="branch" />
            <wire x2="2320" y1="576" y2="576" x1="2304" />
            <wire x2="2384" y1="576" y2="576" x1="2320" />
        </branch>
        <branch name="o(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2320" y="1232" type="branch" />
            <wire x2="2320" y1="1232" y2="1232" x1="2304" />
            <wire x2="2384" y1="1232" y2="1232" x1="2320" />
        </branch>
        <branch name="x6(7:0)">
            <wire x2="880" y1="1072" y2="1072" x1="608" />
            <wire x2="1152" y1="1072" y2="1072" x1="880" />
            <wire x2="1184" y1="1072" y2="1072" x1="1152" />
            <wire x2="1200" y1="1072" y2="1072" x1="1184" />
            <wire x2="1232" y1="1072" y2="1072" x1="1200" />
            <wire x2="1712" y1="1072" y2="1072" x1="1232" />
            <wire x2="1792" y1="1072" y2="1072" x1="1712" />
            <wire x2="1792" y1="1072" y2="1664" x1="1792" />
            <wire x2="1792" y1="1664" y2="1680" x1="1792" />
            <wire x2="1792" y1="1680" y2="1696" x1="1792" />
            <wire x2="1792" y1="1008" y2="1024" x1="1792" />
            <wire x2="1792" y1="1024" y2="1040" x1="1792" />
            <wire x2="1792" y1="1040" y2="1072" x1="1792" />
        </branch>
        <branch name="x7(7:0)">
            <wire x2="880" y1="992" y2="992" x1="608" />
            <wire x2="1184" y1="992" y2="992" x1="880" />
            <wire x2="1680" y1="992" y2="992" x1="1184" />
            <wire x2="1680" y1="992" y2="1056" x1="1680" />
            <wire x2="1680" y1="1056" y2="1616" x1="1680" />
            <wire x2="1680" y1="1616" y2="1632" x1="1680" />
            <wire x2="1680" y1="944" y2="960" x1="1680" />
            <wire x2="1680" y1="960" y2="976" x1="1680" />
            <wire x2="1680" y1="976" y2="992" x1="1680" />
        </branch>
        <branch name="x6(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="1024" type="branch" />
            <wire x2="1904" y1="1024" y2="1024" x1="1888" />
            <wire x2="1920" y1="1024" y2="1024" x1="1904" />
        </branch>
        <branch name="x6(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1904" y="1680" type="branch" />
            <wire x2="1904" y1="1680" y2="1680" x1="1888" />
            <wire x2="1920" y1="1680" y2="1680" x1="1904" />
        </branch>
        <bustap x2="1888" y1="1680" y2="1680" x1="1792" />
        <bustap x2="1888" y1="1024" y2="1024" x1="1792" />
        <bustap x2="1776" y1="960" y2="960" x1="1680" />
        <bustap x2="1776" y1="1616" y2="1616" x1="1680" />
        <branch name="x4(7:0)">
            <wire x2="880" y1="928" y2="928" x1="608" />
            <wire x2="1184" y1="928" y2="928" x1="880" />
            <wire x2="1568" y1="928" y2="928" x1="1184" />
            <wire x2="1568" y1="928" y2="960" x1="1568" />
            <wire x2="1568" y1="960" y2="1552" x1="1568" />
            <wire x2="1568" y1="1552" y2="1568" x1="1568" />
            <wire x2="1568" y1="880" y2="896" x1="1568" />
            <wire x2="1568" y1="896" y2="928" x1="1568" />
        </branch>
        <bustap x2="1664" y1="896" y2="896" x1="1568" />
        <bustap x2="1664" y1="1552" y2="1552" x1="1568" />
        <branch name="x5(7:0)">
            <wire x2="880" y1="864" y2="864" x1="608" />
            <wire x2="1184" y1="864" y2="864" x1="880" />
            <wire x2="1456" y1="864" y2="864" x1="1184" />
            <wire x2="1456" y1="864" y2="1488" x1="1456" />
            <wire x2="1456" y1="1488" y2="1504" x1="1456" />
            <wire x2="1456" y1="816" y2="832" x1="1456" />
            <wire x2="1456" y1="832" y2="864" x1="1456" />
        </branch>
        <iomarker fontsize="28" x="608" y="864" name="x5(7:0)" orien="R180" />
        <iomarker fontsize="28" x="608" y="928" name="x4(7:0)" orien="R180" />
        <iomarker fontsize="28" x="608" y="992" name="x7(7:0)" orien="R180" />
        <iomarker fontsize="28" x="608" y="1072" name="x6(7:0)" orien="R180" />
        <bustap x2="1552" y1="832" y2="832" x1="1456" />
        <bustap x2="1552" y1="1488" y2="1488" x1="1456" />
        <branch name="x2(7:0)">
            <wire x2="1120" y1="800" y2="800" x1="608" />
            <wire x2="1344" y1="800" y2="800" x1="1120" />
            <wire x2="1344" y1="800" y2="1424" x1="1344" />
            <wire x2="1344" y1="1424" y2="1440" x1="1344" />
            <wire x2="1344" y1="752" y2="768" x1="1344" />
            <wire x2="1344" y1="768" y2="800" x1="1344" />
        </branch>
        <iomarker fontsize="28" x="608" y="800" name="x2(7:0)" orien="R180" />
        <bustap x2="1440" y1="768" y2="768" x1="1344" />
        <bustap x2="1440" y1="1424" y2="1424" x1="1344" />
        <branch name="x3(7:0)">
            <wire x2="1216" y1="736" y2="736" x1="608" />
            <wire x2="1216" y1="736" y2="1040" x1="1216" />
            <wire x2="1216" y1="1040" y2="1360" x1="1216" />
            <wire x2="1216" y1="1360" y2="1376" x1="1216" />
            <wire x2="1216" y1="688" y2="704" x1="1216" />
            <wire x2="1216" y1="704" y2="736" x1="1216" />
        </branch>
        <iomarker fontsize="28" x="608" y="736" name="x3(7:0)" orien="R180" />
        <bustap x2="1312" y1="704" y2="704" x1="1216" />
        <bustap x2="1312" y1="1360" y2="1360" x1="1216" />
        <branch name="x0(7:0)">
            <wire x2="1104" y1="672" y2="672" x1="608" />
            <wire x2="1104" y1="672" y2="1296" x1="1104" />
            <wire x2="1104" y1="1296" y2="1312" x1="1104" />
            <wire x2="1104" y1="624" y2="640" x1="1104" />
            <wire x2="1104" y1="640" y2="672" x1="1104" />
        </branch>
        <iomarker fontsize="28" x="608" y="672" name="x0(7:0)" orien="R180" />
        <bustap x2="1200" y1="640" y2="640" x1="1104" />
        <bustap x2="1200" y1="1296" y2="1296" x1="1104" />
        <branch name="x1(7:0)">
            <wire x2="992" y1="608" y2="608" x1="608" />
            <wire x2="992" y1="608" y2="1232" x1="992" />
            <wire x2="992" y1="1232" y2="1248" x1="992" />
            <wire x2="992" y1="560" y2="576" x1="992" />
            <wire x2="992" y1="576" y2="608" x1="992" />
        </branch>
        <iomarker fontsize="28" x="608" y="608" name="x1(7:0)" orien="R180" />
        <bustap x2="1088" y1="576" y2="576" x1="992" />
        <bustap x2="1088" y1="1232" y2="1232" x1="992" />
        <branch name="o(7:0)">
            <wire x2="2480" y1="560" y2="576" x1="2480" />
            <wire x2="2480" y1="576" y2="768" x1="2480" />
            <wire x2="2640" y1="768" y2="768" x1="2480" />
            <wire x2="2480" y1="768" y2="1232" x1="2480" />
            <wire x2="2480" y1="1232" y2="1248" x1="2480" />
        </branch>
        <iomarker fontsize="28" x="2640" y="768" name="o(7:0)" orien="R0" />
        <bustap x2="2384" y1="576" y2="576" x1="2480" />
        <bustap x2="2384" y1="1232" y2="1232" x1="2480" />
        <branch name="sel(2:0)">
            <wire x2="800" y1="1136" y2="1136" x1="608" />
            <wire x2="800" y1="1136" y2="1600" x1="800" />
            <wire x2="800" y1="1600" y2="1744" x1="800" />
            <wire x2="1920" y1="1744" y2="1744" x1="800" />
            <wire x2="1920" y1="1088" y2="1088" x1="800" />
            <wire x2="800" y1="1088" y2="1136" x1="800" />
        </branch>
        <iomarker fontsize="28" x="608" y="1136" name="sel(2:0)" orien="R180" />
    </sheet>
</drawing>