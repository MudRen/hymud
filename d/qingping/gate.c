 inherit ROOM;
void create()
{
        set("short", "ɽׯ����");
        set("long", @LONG
���������ƽɽׯ�Ĵ��ţ���ɫ�ô��ſ���ȥ����ͨͨ��ֻ���Ŷ�
�ϵ�"��ƽɽׯ"������������עĿ���ſ����ż�λ��װ���꣬������ƽ
���µ��ӣ���ǰһ���ϻ�����֦Ҷï�ܣ��ƺ�������ׯ���Ķ��ط�ǡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wuchang1",
  "west" : __DIR__"road",
]));
   set("objects", ([
      __DIR__"npc/lu": 1,
      __DIR__"npc/young": 2,
   ]) ); 
        set("outdoors","qingping");
        set("coor/x",110);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
        
        replace_program(ROOM);
}      
