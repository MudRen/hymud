 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "ׯ�ڵ�");
        set("long", @LONG
һ�������͵�������а��˸ߵ���˶������������罭����
���㣬��������֮����ӿ�Ĳ��Σ��Ĵ�Ʈҡ�����뵽�����е�����,
������Ȼ���¡� 
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"farm4",
                "south" : __DIR__"farm2",
                "east" : __DIR__"farm4",
                "west" : __DIR__"farm6",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",120);
        set("coor/y",-70);
        set("coor/z",0);
        setup(); 
}  
int valid_enter(object me)
{
        
        if(random(50)==1)
                call_out("wind_blow",5,me);
        return 1; 
}
void init()
{
        add_action("do_throw","throw");
} 
int wind_blow(object me)
{
        if(!me || !present(me,this_object()) || !living(me))
                return 1;
        message_vision("����΢������������ʲô��Ҷ֮�����(throw)�ڿ��еĻ���һ�������Ʈȥ�ɡ�\n",me);
        set("΢����",1);
   call_out("wind_stop",20);
        return 1;
} 
int wind_stop()
{
        message("vision","��ͣ�ˡ�����\n",this_object());
        delete("΢����");
        return 1;
} 
int do_throw(string arg)
{
        string leaf_name;
        object leaf;
        
        if(!arg) return notify_fail("��Ҫ��ʲô��\n");
        leaf = present(arg, this_player());
        if(!leaf)
                return notify_fail("��û���������ѽ��\n");
        if(!leaf->query("castable"))
                return notify_fail("��������ײ�������\n");
        if(!query("΢����"))
                return notify_fail("����û�з磬�ײ�������\n");
        if(this_player()->query("age")>13||this_player()->query("����B/�䵱_��Ҷ",1))
                return notify_fail("���Ѿ�����С�����ˡ�\n");
        leaf_name=leaf->query("name");
        message_vision("$N��һƬ"+leaf_name+NOR"���ڷ��У�������Ʈ���ˡ�\n",this_player());
        if(leaf_name==HIR"��Ҷ"NOR)
this_player()->set("����B/�䵱_��Ҷ", 1+random(10));
        destruct(leaf);
        return 1;
}
                  
