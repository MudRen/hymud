 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һƬï�ܵ������֣����з�����������Ӣ�ͷף�һ�㵭���ı�����
��������Ĳ��㣬�����ڿ���֮�С�ż����һ�����������������Գ��ľ�����
�����С·�ѱ��仨���������ѱ治���ۼ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"taolin2",
  "west" : __DIR__"taolin",
])); 
        set("item_desc", ([
            "����": "�����Ͻ����˴����ҡ�\n",
            "peach tree": "�����Ͻ����˴����ҡ�\n",
        ]) ); 
        set("outdoors","taoyuan");
        set("coor/x",120);
        set("coor/y",-30);
        set("coor/z",0);
        set("peach_amount",5);
        setup();
} 
void init() 
{
   add_action("do_pick", "pick");
} 
int do_pick(string arg)
{
   object me, zhi; 
   me = this_player(); 
   if(!arg || arg != "peach" && arg != "����") return 0;        
   zhi = new(__DIR__"obj/taozi");
   zhi->move(me);
 
   message_vision("\n$N����ժ��һ������������������\n", me);
        
   return 1;    
}       
