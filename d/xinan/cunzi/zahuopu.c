//Writen by lnwm
//zahuopu.c

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
ï�ܵ�һƬ�񺣣����Ӳ����ִ󣬵�����ͦ�βԴ䣬΢�����ʱ����
ɳɳ��������������˼�������ӵ�ɽ������ͷ�����ţ������������Ϊ��
������������ɽ���ǽ����ǿ���������ɽ�¡����������������ţ�����
���Ĵ���ؽ���ĺӵ�֮�С�
LONG
    );
    set("exits", ([
        "southwest"     :    __DIR__ "zhulin",
        ]));
    set("objects", ([           
         __DIR__ "npc/kanzhu" : 1,
    ]) );
    set("outdoors","lnwm");
    setup();
}


