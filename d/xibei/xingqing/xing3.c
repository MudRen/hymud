// room: xing3.c
//by lnwm 97-09-12


inherit ROOM;

void create()
{
        set("short", "�ƺ��ذ�");
        set("long", @LONG
�����������ĳ�ɽ����֮��, ǰ��ĵ�·Խ�����. �ƺ�����ķ��Ľ��ӵ�
�����ˢ���쳣����. ����û�е�·. �Ӱ��������վ��ĸ�ɽ, ɽ�����, ͦ��
����. ����ǰ�ͽ������Ĺ��Ĺ�����. Խ����Խ����, ֻ�г�Ĭ�Ļƺ���������
��. 
LONG
        );
    set("exits", ([ 
                "southwest"     :       __DIR__ "xing2",
                "northeast"     :       __DIR__ "xing4",
        ]));
        set("outdoors","xingqing");
        setup();
}                       


