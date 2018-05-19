<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="led(7:0)" />
        <signal name="XLXN_30(7:0)" />
        <signal name="XLXN_32" />
        <signal name="XLXN_33" />
        <signal name="sw(3:0)" />
        <signal name="XLXN_44(3:0)" />
        <signal name="sw(3)" />
        <signal name="dout(63:0)" />
        <signal name="XLXN_48(7:0)" />
        <signal name="dout(55:48)" />
        <signal name="dout(63:56)" />
        <signal name="dout(39:32)" />
        <signal name="dout(47:40)" />
        <signal name="dout(23:16)" />
        <signal name="dout(31:24)" />
        <signal name="dout(7:0)" />
        <signal name="dout(15:8)" />
        <signal name="sw(2:0)" />
        <signal name="XLXN_59(7:0)" />
        <signal name="XLXN_62" />
        <port polarity="Output" name="led(7:0)" />
        <port polarity="Input" name="sw(3:0)" />
        <blockdef name="mux8t1_8">
            <timestamp>2018-5-19T7:7:13</timestamp>
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
        <blockdef name="buf8">
            <timestamp>2018-5-19T6:40:53</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="rom">
            <timestamp>2018-5-19T6:40:47</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="buf8" name="XLXI_2">
            <blockpin signalname="XLXN_48(7:0)" name="din(7:0)" />
            <blockpin signalname="led(7:0)" name="dout(7:0)" />
        </block>
        <block symbolname="rom" name="XLXI_6">
            <blockpin signalname="sw(3)" name="addr" />
            <blockpin signalname="dout(63:0)" name="dout(63:0)" />
        </block>
        <block symbolname="mux8t1_8" name="XLXI_8">
            <blockpin signalname="dout(55:48)" name="x6(7:0)" />
            <blockpin signalname="dout(63:56)" name="x7(7:0)" />
            <blockpin signalname="dout(39:32)" name="x4(7:0)" />
            <blockpin signalname="dout(47:40)" name="x5(7:0)" />
            <blockpin signalname="dout(23:16)" name="x2(7:0)" />
            <blockpin signalname="dout(31:24)" name="x3(7:0)" />
            <blockpin signalname="dout(7:0)" name="x0(7:0)" />
            <blockpin signalname="dout(15:8)" name="x1(7:0)" />
            <blockpin signalname="sw(2:0)" name="sel(2:0)" />
            <blockpin signalname="XLXN_48(7:0)" name="o(7:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1984" y="672" name="XLXI_2" orien="R0">
        </instance>
        <branch name="led(7:0)">
            <wire x2="2512" y1="640" y2="640" x1="2368" />
        </branch>
        <iomarker fontsize="28" x="2512" y="640" name="led(7:0)" orien="R0" />
        <branch name="sw(3:0)">
            <wire x2="432" y1="704" y2="704" x1="416" />
            <wire x2="432" y1="704" y2="816" x1="432" />
            <wire x2="432" y1="816" y2="832" x1="432" />
            <wire x2="432" y1="608" y2="624" x1="432" />
            <wire x2="432" y1="624" y2="704" x1="432" />
        </branch>
        <bustap x2="528" y1="624" y2="624" x1="432" />
        <bustap x2="528" y1="816" y2="816" x1="432" />
        <iomarker fontsize="28" x="416" y="704" name="sw(3:0)" orien="R180" />
        <instance x="592" y="848" name="XLXI_6" orien="R0">
        </instance>
        <branch name="sw(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="576" y="816" type="branch" />
            <wire x2="576" y1="816" y2="816" x1="528" />
            <wire x2="592" y1="816" y2="816" x1="576" />
        </branch>
        <branch name="dout(63:0)">
            <wire x2="1008" y1="816" y2="816" x1="976" />
            <wire x2="1008" y1="816" y2="880" x1="1008" />
            <wire x2="1008" y1="880" y2="944" x1="1008" />
            <wire x2="1008" y1="944" y2="960" x1="1008" />
            <wire x2="1008" y1="480" y2="496" x1="1008" />
            <wire x2="1008" y1="496" y2="560" x1="1008" />
            <wire x2="1008" y1="560" y2="624" x1="1008" />
            <wire x2="1008" y1="624" y2="688" x1="1008" />
            <wire x2="1008" y1="688" y2="736" x1="1008" />
            <wire x2="1008" y1="736" y2="752" x1="1008" />
            <wire x2="1008" y1="752" y2="816" x1="1008" />
        </branch>
        <instance x="1376" y="1040" name="XLXI_8" orien="R0">
        </instance>
        <branch name="XLXN_48(7:0)">
            <wire x2="1792" y1="496" y2="496" x1="1760" />
            <wire x2="1792" y1="496" y2="640" x1="1792" />
            <wire x2="1984" y1="640" y2="640" x1="1792" />
        </branch>
        <branch name="dout(55:48)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1360" y="496" type="branch" />
            <wire x2="1360" y1="496" y2="496" x1="1104" />
            <wire x2="1376" y1="496" y2="496" x1="1360" />
        </branch>
        <branch name="dout(63:56)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1360" y="560" type="branch" />
            <wire x2="1360" y1="560" y2="560" x1="1104" />
            <wire x2="1376" y1="560" y2="560" x1="1360" />
        </branch>
        <branch name="dout(39:32)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1360" y="624" type="branch" />
            <wire x2="1360" y1="624" y2="624" x1="1104" />
            <wire x2="1376" y1="624" y2="624" x1="1360" />
        </branch>
        <branch name="dout(47:40)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1360" y="688" type="branch" />
            <wire x2="1360" y1="688" y2="688" x1="1104" />
            <wire x2="1376" y1="688" y2="688" x1="1360" />
        </branch>
        <branch name="dout(23:16)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1360" y="752" type="branch" />
            <wire x2="1360" y1="752" y2="752" x1="1104" />
            <wire x2="1376" y1="752" y2="752" x1="1360" />
        </branch>
        <branch name="dout(31:24)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1360" y="816" type="branch" />
            <wire x2="1360" y1="816" y2="816" x1="1104" />
            <wire x2="1376" y1="816" y2="816" x1="1360" />
        </branch>
        <branch name="dout(7:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1360" y="880" type="branch" />
            <wire x2="1360" y1="880" y2="880" x1="1104" />
            <wire x2="1376" y1="880" y2="880" x1="1360" />
        </branch>
        <branch name="dout(15:8)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1360" y="944" type="branch" />
            <wire x2="1360" y1="944" y2="944" x1="1104" />
            <wire x2="1376" y1="944" y2="944" x1="1360" />
        </branch>
        <branch name="sw(2:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1360" y="1008" type="branch" />
            <wire x2="992" y1="624" y2="624" x1="528" />
            <wire x2="992" y1="624" y2="1008" x1="992" />
            <wire x2="1360" y1="1008" y2="1008" x1="992" />
            <wire x2="1376" y1="1008" y2="1008" x1="1360" />
        </branch>
        <bustap x2="1104" y1="496" y2="496" x1="1008" />
        <bustap x2="1104" y1="560" y2="560" x1="1008" />
        <bustap x2="1104" y1="624" y2="624" x1="1008" />
        <bustap x2="1104" y1="688" y2="688" x1="1008" />
        <bustap x2="1104" y1="752" y2="752" x1="1008" />
        <bustap x2="1104" y1="816" y2="816" x1="1008" />
        <bustap x2="1104" y1="880" y2="880" x1="1008" />
        <bustap x2="1104" y1="944" y2="944" x1="1008" />
    </sheet>
</drawing>