//Writen by lnwm
//lroad1.c

inherit ROOM;

void create()
{
    set("short", "С��·");
    set("long", @LONG
һ��С���ӵ���ڣ�����λ�����ɽ�ĺ�ɽ�����������������ɽ��
�̵�ɽɫ����͸�����ص���ɫ���ɵ����ϣ��������ܿ�������Сé�ݵ�
�ݶ�.ʱ���м��ƴ����������ϣ�������ƾ���˼����ľ���
LONG
        );
    set("outdoors","lnwm");
    set("exits", ([
        "south"     :        "/d/xinan/qingcheng_shan",
//        "west"      :       __DIR__ "houshan",
        "north"     :       __DIR__ "lroad2",
        ]));
    set("objects",([
                __DIR__ "npc/kid" : 1,
                  ])                  
    );
    setup();
    replace_program(ROOM);
}


