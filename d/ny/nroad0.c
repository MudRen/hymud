
// Room: /d/snow/eroad3.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long",
"����һ��˵����˵խ��Ҳ��խ��ɽ·��·���ü���������̦�Ĵ�ʯ�̳ɣ�������һ����\n"
"�أ��������������Ұ��ɽ���м��䷿�ݴ������ּ䣬������һ��Ժǽ�����洫�����ӵ���\n"
"����ɽ·������ͨ��ɽ�꣬ɽ·�����ν�һ����ʯ��·��\n"
);
        set("exits", ([ /* sizeof() == 2 */
]));
	set("no_clean_up",0);
        set("outdoors", "ny");
        setup();
        replace_program(ROOM);
}
