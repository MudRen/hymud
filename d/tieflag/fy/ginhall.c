 inherit ROOM;
void create()
{
        set("short", "�ھ���Ժ");
        set("long", @LONG
�������ھֻ��������֮�࣬��Ϣ���ɵ�Ժ�ӡ�Ժ�ӵ�����������˵ļ��ż�
����ͣ������������ɹ�·��ġ�Ժ�ӵ���Χ�м���С�����ǹ�û�мҵ�������
��ס�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                  "west" : __DIR__"ghall",
                  "east"  : __DIR__"gke1", 
                  "north" : __DIR__"gke2",
                  "south" : __DIR__"gke3",
]));
        set("item_desc", ([
                "bamboo": "��Щ��ͺ������Ų���������壩��\n",
                "���" : "��Щ��ͺ������Ų���������壩��\n",
                "�������" : "��Щ��ͺ������Ų���������壩��\n"
        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",30);
        set("coor/y",40);
        set("coor/z",0);
        setup();
} 
void init()
{ 
        add_action("do_move", "move");
} 
int do_move(string arg)
{
        object cock;
        if ( !arg || (arg != "bamboo" && arg != "���" && arg != "�������")) {
                return notify_fail("��Ҫ�ᶯʲô��\n");
        }
        if( query("amount") > 10 ) 
                return notify_fail("��Ų������붼�����ŵ��ܹ��ˡ�\n" );
        cock = new(__DIR__"npc/cockroach");
   if(cock) cock->move(this_object());
        message_vision("$NŲ������ͣ�һֻ"+cock->name()+"�ɿ�����˳�����\n", this_player());
        add("amount",1);
        return 1;
} 
void reset()
{
        ::reset();
        set("amount",0);
}      
