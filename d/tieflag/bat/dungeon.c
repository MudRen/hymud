 // dungeon.c
inherit ROOM; 
void create()
{
        set("short", "����");
        set("long", @LONG
����һ����ɭ�ֲ��ĵ�����ƺ��кܶ��ڴ���ȥ��ԩ��Ʈ������������µ�
�綾��Ѫ���������ȥ������һ��൨���ĵ��������ţ��ϱ�ǽ�Ǵ�һ��������
�Ϸ���һ�ˣ���֪�����ǻ
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south"   : __DIR__"d5",
])); 
        set("objects", ([
                __DIR__"npc/xunluo1" : 1,
                __DIR__"npc/dizi" : 2,
                __DIR__"npc/bianfu2" : 1,
                __DIR__"npc/bianfu1" : 1,
                __DIR__"npc/hu" : 1,
        "/d/huanghe/yyd/npc/huajy":1,
        ]) );  
        set("coor/x",3270);
        set("coor/y",50);
        set("coor/z",-30);
        setup();
        replace_program(ROOM);
}