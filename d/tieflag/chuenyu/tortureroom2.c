 inherit ROOM;
void create()
{
        set("short", "�̷�");
        set("long", @LONG
�����̷��ѱ�Ǭ�µ�Ѫ��Ȼ�ɰ���ɫ��ɢ�����˱ǵ��ȳ���ǽ�Ϲ�����
��ʽ�������Ͼߡ��̷��ĵ���ɢ�����������������������á�ż��֮�䣬
�㻹������������֨֨���ļ������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
//  "south" : __DIR__"tunnel6",
  "south" : __DIR__"tortureroom",
]));
        set("objects", ([
                __DIR__"npc/highrat": 2, 
                __DIR__"npc/guard2" : 2
        ]) ); 
//        set("coor/x",130);
        set("coor/x",150);
        set("coor/y",150);
        set("coor/z",20);
        setup();
}       