// room: xing0.c
//by lnwm 97-09-12


inherit ROOM;

void create()
{
        set("short", "�ƺ��ذ�");
        set("long", @LONG
���������������, �����ػƺӱ���. ��������ɽ��, ��������ƺ�, ��
�໹����Ϊƽ̹�Ļ���·. ���������������̽�ϡ. ·�߳������Ӳݴ���, ����
���ɱ����·. ǰ�治Զ�����춼ɽ�߸ߵ�����.
LONG
        );
    set("exits", ([ 
                "southwest"     :       "/d/xibei/jincheng_guan",
                "northeast"     :       __DIR__ "xing1",
        ]));
        set("outdoors","xingqing");
        setup();
}                       


