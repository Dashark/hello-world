<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="x1(3:0)" />
        <signal name="x0(3:0)" />
        <signal name="x3(3:0)" />
        <signal name="x2(3:0)" />
        <signal name="x5(3:0)" />
        <signal name="x4(3:0)" />
        <signal name="x7(3:0)" />
        <signal name="XLXN_22(3:0)" />
        <signal name="XLXN_24(3:0)" />
        <signal name="XLXN_26(3:0)" />
        <signal name="XLXN_29(3:0)" />
        <signal name="XLXN_33(3:0)" />
        <signal name="XLXN_34(3:0)" />
        <signal name="o(3:0)" />
        <signal name="x6(3:0)" />
        <signal name="sel(2:0)" />
        <signal name="sel(0)" />
        <signal name="sel(1)" />
        <signal name="sel(2)" />
        <port polarity="Input" name="x1(3:0)" />
        <port polarity="Input" name="x0(3:0)" />
        <port polarity="Input" name="x3(3:0)" />
        <port polarity="Input" name="x2(3:0)" />
        <port polarity="Input" name="x5(3:0)" />
        <port polarity="Input" name="x4(3:0)" />
        <port polarity="Input" name="x7(3:0)" />
        <port polarity="Output" name="o(3:0)" />
        <port polarity="Input" name="x6(3:0)" />
        <port polarity="Input" name="sel(2:0)" />
        <blockdef name="mux4t1">
            <timestamp>2018-5-18T8:55:45</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-172" height="24" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
        </blockdef>
        <block symbolname="mux4t1" name="XLXI_1">
            <blockpin signalname="x1(3:0)" name="a(3:0)" />
            <blockpin signalname="sel(0)" name="sel" />
            <blockpin signalname="x0(3:0)" name="b(3:0)" />
            <blockpin signalname="XLXN_22(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="mux4t1" name="XLXI_2">
            <blockpin signalname="x3(3:0)" name="a(3:0)" />
            <blockpin signalname="sel(0)" name="sel" />
            <blockpin signalname="x2(3:0)" name="b(3:0)" />
            <blockpin signalname="XLXN_26(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="mux4t1" name="XLXI_3">
            <blockpin signalname="x5(3:0)" name="a(3:0)" />
            <blockpin signalname="sel(0)" name="sel" />
            <blockpin signalname="x4(3:0)" name="b(3:0)" />
            <blockpin signalname="XLXN_24(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="mux4t1" name="XLXI_4">
            <blockpin signalname="x7(3:0)" name="a(3:0)" />
            <blockpin signalname="sel(0)" name="sel" />
            <blockpin signalname="x6(3:0)" name="b(3:0)" />
            <blockpin signalname="XLXN_34(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="mux4t1" name="XLXI_5">
            <blockpin signalname="XLXN_26(3:0)" name="a(3:0)" />
            <blockpin signalname="sel(1)" name="sel" />
            <blockpin signalname="XLXN_22(3:0)" name="b(3:0)" />
            <blockpin signalname="XLXN_29(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="mux4t1" name="XLXI_6">
            <blockpin signalname="XLXN_34(3:0)" name="a(3:0)" />
            <blockpin signalname="sel(1)" name="sel" />
            <blockpin signalname="XLXN_24(3:0)" name="b(3:0)" />
            <blockpin signalname="XLXN_33(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="mux4t1" name="XLXI_7">
            <blockpin signalname="XLXN_33(3:0)" name="a(3:0)" />
            <blockpin signalname="sel(2)" name="sel" />
            <blockpin signalname="XLXN_29(3:0)" name="b(3:0)" />
            <blockpin signalname="o(3:0)" name="o(3:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="784" y="720" name="XLXI_1" orien="R0">
        </instance>
        <instance x="784" y="1088" name="XLXI_2" orien="R0">
        </instance>
        <instance x="784" y="1456" name="XLXI_3" orien="R0">
        </instance>
        <instance x="784" y="1824" name="XLXI_4" orien="R0">
        </instance>
        <instance x="1376" y="896" name="XLXI_5" orien="R0">
        </instance>
        <instance x="1376" y="1632" name="XLXI_6" orien="R0">
        </instance>
        <instance x="1872" y="1232" name="XLXI_7" orien="R0">
        </instance>
        <branch name="x1(3:0)">
            <wire x2="784" y1="560" y2="560" x1="736" />
        </branch>
        <branch name="x0(3:0)">
            <wire x2="784" y1="688" y2="688" x1="736" />
        </branch>
        <branch name="x3(3:0)">
            <wire x2="784" y1="928" y2="928" x1="736" />
        </branch>
        <branch name="x2(3:0)">
            <wire x2="784" y1="1056" y2="1056" x1="736" />
        </branch>
        <branch name="x5(3:0)">
            <wire x2="784" y1="1296" y2="1296" x1="736" />
        </branch>
        <branch name="x4(3:0)">
            <wire x2="784" y1="1424" y2="1424" x1="736" />
        </branch>
        <branch name="x7(3:0)">
            <wire x2="784" y1="1664" y2="1664" x1="736" />
        </branch>
        <branch name="XLXN_22(3:0)">
            <wire x2="1232" y1="560" y2="560" x1="1168" />
            <wire x2="1232" y1="560" y2="864" x1="1232" />
            <wire x2="1312" y1="864" y2="864" x1="1232" />
            <wire x2="1376" y1="864" y2="864" x1="1312" />
        </branch>
        <branch name="XLXN_24(3:0)">
            <wire x2="1248" y1="1296" y2="1296" x1="1168" />
            <wire x2="1248" y1="1296" y2="1600" x1="1248" />
            <wire x2="1312" y1="1600" y2="1600" x1="1248" />
            <wire x2="1376" y1="1600" y2="1600" x1="1312" />
        </branch>
        <branch name="XLXN_26(3:0)">
            <wire x2="1232" y1="928" y2="928" x1="1168" />
            <wire x2="1264" y1="928" y2="928" x1="1232" />
            <wire x2="1264" y1="736" y2="928" x1="1264" />
            <wire x2="1312" y1="736" y2="736" x1="1264" />
            <wire x2="1376" y1="736" y2="736" x1="1312" />
        </branch>
        <branch name="XLXN_34(3:0)">
            <wire x2="1232" y1="1664" y2="1664" x1="1168" />
            <wire x2="1328" y1="1664" y2="1664" x1="1232" />
            <wire x2="1328" y1="1472" y2="1472" x1="1312" />
            <wire x2="1376" y1="1472" y2="1472" x1="1328" />
            <wire x2="1328" y1="1472" y2="1664" x1="1328" />
        </branch>
        <branch name="o(3:0)">
            <wire x2="2320" y1="1072" y2="1072" x1="2256" />
        </branch>
        <iomarker fontsize="28" x="736" y="560" name="x1(3:0)" orien="R180" />
        <iomarker fontsize="28" x="736" y="688" name="x0(3:0)" orien="R180" />
        <iomarker fontsize="28" x="736" y="928" name="x3(3:0)" orien="R180" />
        <iomarker fontsize="28" x="736" y="1056" name="x2(3:0)" orien="R180" />
        <iomarker fontsize="28" x="736" y="1296" name="x5(3:0)" orien="R180" />
        <iomarker fontsize="28" x="736" y="1424" name="x4(3:0)" orien="R180" />
        <iomarker fontsize="28" x="736" y="1664" name="x7(3:0)" orien="R180" />
        <branch name="x6(3:0)">
            <wire x2="784" y1="1792" y2="1792" x1="752" />
        </branch>
        <iomarker fontsize="28" x="752" y="1792" name="x6(3:0)" orien="R180" />
        <iomarker fontsize="28" x="2320" y="1072" name="o(3:0)" orien="R0" />
        <branch name="sel(2:0)">
            <wire x2="528" y1="1936" y2="1936" x1="304" />
            <wire x2="1280" y1="1936" y2="1936" x1="528" />
            <wire x2="2720" y1="1936" y2="1936" x1="1280" />
            <wire x2="2736" y1="1936" y2="1936" x1="2720" />
        </branch>
        <iomarker fontsize="28" x="304" y="1936" name="sel(2:0)" orien="R180" />
        <bustap x2="2720" y1="1936" y2="1840" x1="2720" />
        <bustap x2="1280" y1="1936" y2="1840" x1="1280" />
        <bustap x2="528" y1="1936" y2="1840" x1="528" />
        <branch name="sel(0)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="528" y="1808" type="branch" />
            <wire x2="736" y1="624" y2="624" x1="528" />
            <wire x2="784" y1="624" y2="624" x1="736" />
            <wire x2="528" y1="624" y2="992" x1="528" />
            <wire x2="528" y1="992" y2="1360" x1="528" />
            <wire x2="528" y1="1360" y2="1728" x1="528" />
            <wire x2="736" y1="1728" y2="1728" x1="528" />
            <wire x2="784" y1="1728" y2="1728" x1="736" />
            <wire x2="528" y1="1728" y2="1808" x1="528" />
            <wire x2="528" y1="1808" y2="1840" x1="528" />
            <wire x2="736" y1="1360" y2="1360" x1="528" />
            <wire x2="784" y1="1360" y2="1360" x1="736" />
            <wire x2="736" y1="992" y2="992" x1="528" />
            <wire x2="784" y1="992" y2="992" x1="736" />
        </branch>
        <branch name="sel(1)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1280" y="1808" type="branch" />
            <wire x2="1312" y1="800" y2="800" x1="1280" />
            <wire x2="1376" y1="800" y2="800" x1="1312" />
            <wire x2="1280" y1="800" y2="1536" x1="1280" />
            <wire x2="1280" y1="1536" y2="1808" x1="1280" />
            <wire x2="1280" y1="1808" y2="1840" x1="1280" />
            <wire x2="1312" y1="1536" y2="1536" x1="1280" />
            <wire x2="1376" y1="1536" y2="1536" x1="1312" />
        </branch>
        <branch name="sel(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2720" y="1808" type="branch" />
            <wire x2="1808" y1="1136" y2="1136" x1="1344" />
            <wire x2="1872" y1="1136" y2="1136" x1="1808" />
            <wire x2="1344" y1="1136" y2="1808" x1="1344" />
            <wire x2="2720" y1="1808" y2="1808" x1="1344" />
            <wire x2="2720" y1="1808" y2="1840" x1="2720" />
        </branch>
        <branch name="XLXN_29(3:0)">
            <wire x2="1824" y1="736" y2="736" x1="1760" />
            <wire x2="1824" y1="736" y2="992" x1="1824" />
            <wire x2="1792" y1="992" y2="1200" x1="1792" />
            <wire x2="1808" y1="1200" y2="1200" x1="1792" />
            <wire x2="1872" y1="1200" y2="1200" x1="1808" />
            <wire x2="1824" y1="992" y2="992" x1="1792" />
        </branch>
        <branch name="XLXN_33(3:0)">
            <wire x2="1808" y1="1472" y2="1472" x1="1760" />
            <wire x2="1824" y1="1072" y2="1072" x1="1808" />
            <wire x2="1872" y1="1072" y2="1072" x1="1824" />
            <wire x2="1808" y1="1072" y2="1120" x1="1808" />
            <wire x2="1856" y1="1120" y2="1120" x1="1808" />
            <wire x2="1856" y1="1120" y2="1264" x1="1856" />
            <wire x2="1856" y1="1264" y2="1264" x1="1808" />
            <wire x2="1808" y1="1264" y2="1472" x1="1808" />
        </branch>
    </sheet>
</drawing>