// /d/tianshui/duchang.c

inherit ROOM;

void create()
{
        set("short", "��ˮ�Ĺ�");
        set("long", @LONG
�������Զ����������ˮ�Ĺݡ��������˷��Ľк�������
�ӡ�Ԫ��������������ײ��ʹ��Ҳ����ѪҺ��������������Ҳ��
(bet)�����������������űߵ�����(paizi)д������ĶĹ档��
����¥��ͨ���¥��
LONG
        );

        set("exits", ([
                "west" : __DIR__"nroad2",
		  "up" : __DIR__"duchang2"
                     ]));
	set("objects",([
	__DIR__"npc/judge" : 1,
]));
        
        setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "up")
		return notify_fail("ͨ��¥�ϵ��Ž����ţ���ʱ����������Լ�Ľк�����¥�Ϻ���Ҳ�ڶ�Ǯ��\n");
	return ::valid_leave(me,dir);
}
