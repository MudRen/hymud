// Room: /d/snow/smithy.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������һ��������ӣ��ӻ�¯��ð���Ļ�⽫ǽ��ӳ��ͨ�죬
���ӵĽ���������˸�ʽ���������Ʒ��δ���Ʒ�����ǳ�ͷ��
���������ӡ������ȣ����������������õ��������졣���ڿ���
��Ӫ����˵��������ʱ���ɵ�����������������׵Ļ
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eroad2",
]));

        set("objects", ([
                __DIR__"npc/smith": 1 ]) );
        setup();
        replace_program(ROOM);
}
