 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������Ȼ�Ͳ��翿�㳡��ͷ�����ˣ��������һ��С¥��¥������Ʈ�Ű�ɫ��
ˮ�����������������������𡣴�ֵ������ǹ����������������ɣ�õĽ����ã�
���������ǵ������ֵ�һ��������Ҫȥ�����Ƴ������˲�����佻��á�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"nwind2",
                "north" : __DIR__"nwind4",
                "east" : __DIR__"hfeng",
                "west" : __DIR__"jlong",
        ]));
        set("objects", ([
                __DIR__"npc/fat" : 1,
                __DIR__"npc/patrol_soldier": 1,
        ]) );
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
