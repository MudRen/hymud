// Room: /d/snow/tree.c
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����������һ��޴�������ϣ�ï�ܵ�֦Ҷɦ������Щ������
ǰ��һ���ִ����֦�����˷���һ����ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "down" : __DIR__"guangchang",
]));
        set("objects", ([
                __DIR__"npc/abao": 1
        ]) );
        setup();
        replace_program(ROOM);
}
