// room: xing6.c
//by lnwm 97-09-12


inherit ROOM;

void create()
{
        set("short", "�ƺ��ذ�");
        set("long", @LONG
�߳�ɽ��, ����ǰ��һƬ����Ⱥɽ�ͻƺ�֮���ƽԭ. ���������������, 
����ǰ�������ĵ��׸����츮. ��������, ���̽�������������, ���ܸе�, ��
��ķ����Ļ�������ԭ�������ò�ͬ. 
����ǰ, �������ܿ���һ������. �Ǿ��������׸����츮. 
LONG
        );
    set("exits", ([ 
                "southwest"     :       __DIR__ "xing5",
                "northeast"     :       __DIR__ "xing7",
        ]));
        set("outdoors","xingqing");
        setup();
}                       


