 inherit ROOM;
void create()
{
        set("short", "�Ϸ��");
        set("long", @LONG
�ֵ�����ˮϴ����ô�ĸɾ�������������·������羵��������߷��ߴ��ΰ��
˫�˺ϱ�������ʮ��һ�꣬������������ߡ��������һ��ǧ��޶�������������
���ԣ�������ǽ�Ǯ����ܶ档��ֶ����լ����һ�߸ߵ�ʮ�ּܣ�һЩ�𷢱��ۣ�
�������۵��˲�ʱ�ĳ������롣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind3",
  "north" : __DIR__"swind1",
  "east" : __DIR__"church",
  "west" : __DIR__"jinqian",
]));
        set("objects", ([
                __DIR__"npc/dtz1" : 2,
                __DIR__"npc/patrol_soldier": 1,
       ]) );
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
