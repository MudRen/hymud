 //troad3
inherit ROOM; 
void create()
{
        set("short", "Σ��ǰ");
        set("long", @LONG
С·����ͻȻ�жϣ�һ��Σ�µ�ס���ȥ·�������������ƣ��Ե���Ϊ�Ź֡�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"troad2",
]));
        set("objects", ([
        __DIR__"npc/cat" : 1,
                        ]) ); 
        set("item_desc", ([
                "tree": "���������(tree)���ܣ��ƺ������˹����á�\n",
                "����": "���������(tree)���ܣ��ƺ������˹����á�\n" 
        ]) );
        
        set("outdoors","tieflag");      
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",25);
        setup();
}
void init()
{
        add_action("do_west", "w");
        add_action("do_west", "west");
}
int do_west(string arg)
{
        object me;
        object room;
        object *inv;
        int i;
        me = this_player();
        inv = all_inventory(me);
        if(!me->query_temp("mark/cat"))
        {
        for(i=0; i<sizeof(inv); i++)
        {
         if((string)(inv[i]->query("id")) == "leaf" && inv[i]->query("real"))       
          {
           me->set_temp("mark/cat",1);
           destruct(inv[i]);
           break;
          }
        }
        }
        if(me->query_temp("mark/cat"))
        {       
//              me->delete_temp("mark/cat");
                message_vision("$N�ƿ��������������һ��ɽ�����˽�ȥ��\n", me);
                room = load_object(__DIR__"dong0");
                if(room) me->move(room);
                return 1;
        }
        return 0;
} 
