// room: xing1.c
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
                "southwest"     :       __DIR__ "xing0",
                "northeast"     :       __DIR__ "xing2",
        ]));
        set("outdoors","xingqing");
        setup();
}                       


