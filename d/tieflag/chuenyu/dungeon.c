 // Room: /d/chuenyu/dungeon.c
inherit ROOM; 
void create()
{
        set("short", "�̷�");
        set("long", @LONG
�㴦��һ����ʪ�ĵ�������εĽ��������һЩ�ɲݣ��ɲ���մ����
����ɫ��Ѫ����������ñ��������������ǽ�ϡ�ż��֮�䣬�㻹��������
����֨֨���ļ������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tunnel3",
  "north"   : __DIR__"tunnel4",
])); 
        set("objects", ([
                __DIR__"npc/wenqq" : 1,
                __DIR__"npc/chuenyu" : 1,
                __DIR__"xiaojuan2" : 1,
        ]) ); 
        set("coor/x",130);
        set("coor/y",150);
        set("coor/z",20);
        setup();
}     
