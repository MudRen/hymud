 inherit ROOM;
void create()
{
        set("short", "ɽ�ȿ�");
        set("long", @LONG
·������һ��ʯ��������д��������׭�֣���ɽ��        
��ɽ�ȿ�ȥ��һ������������С·������ڣ�����һΣ��ǰͻȻ�жϡ�
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"palace/palace_palace",
  "eastdown" : __DIR__"troad1",
]));
        set("outdoors","tieflag");      
        
        set("coor/x",160);
        set("coor/y",-10);
        set("coor/z",30);
        setup();
}    
