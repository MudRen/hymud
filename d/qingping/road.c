 inherit ROOM;
void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
һ������խ����ʯ·��·�ľ�ͷ���Ǻպ���������ƽɽׯ��·������
���࣬�����Ķ�������ֺ��ܣ���Ϊ��ƽ���Ͱ�����������ԭ���ֵĵ�һ
���֣�һ����ƽ���������޵����£�����Ľ�����������ࡣ
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"gate",
  //"southwest" : "/d/jinan/road2",
  "north" : "/d/jinan/road3",
])); 
        set("outdoors","qingping");
        set("coor/x",100);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
        
        replace_program(ROOM);
}       
