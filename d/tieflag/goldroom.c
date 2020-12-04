#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ر���");
        set("long", @LONG 
����ǽ�ھ����������ɣ������������һ�鼫�����ڡ�
�����б��ϰ�ͷ���������������챦����һ����������������
����֮���ľ�Ʒ������һ������Ƕ���鱦�ĳ����ƺ��Ѿ���
�ʣ����⾧Ө��Ŀ�����ɷ��
LONG
        );
         
       set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gu5",
]));
         
        set("item_desc", ([
                "sword": "
��һ������һ�Ѽ�ֵ���ǵı�������������ġ�\n",
                "����": "
��һ������һ�Ѽ�ֵ���ǵı�������������ġ�\n",
                "���": "
һ���龧Ө�����񣬷·𾭳��������ִ����� \n", 
                "jade": "
һ���龧Ө�����񣬷·𾭳��������ִ����� \n",
        ]) ); 
        set("coor/x",80);
        set("coor/y",0);
        set("coor/z",-20);
        setup();
      
}
 
 void init()
{
   add_action("do_open","push"); 
   add_action("do_pull","pull");
} 
           
int do_open(string arg)
{
        object room;
         object me;  
        me=this_player();
        if(!objectp(room = find_object(__DIR__"girlroom")))
        room = load_object(__DIR__"girlroom");
        switch (arg)
         {
         case "jade":
         case "���":
             if(query("exits/east")) return notify_fail("���Ѿ��ǿ����ˡ�");
             message_vision("$N�����������һ��������ϳ���һ��С�š�\n",this_player());
             set("exits/east",__DIR__"girlroom");
                room->set("exits/west",__DIR__"goldroom");
             call_out("closepath",5,room);
             return 1;
         }
}
void closepath(object room)
{
tell_object(this_object(),"С�ţ�֨����һ���ֹ����ˡ�\n");
delete("exits/east");
room->delete("exits/west");
}
int do_pull(string arg)
{
        object swo;
        string *limbs;
        if( query_temp("mark/been_get")) return notify_fail("���ѱ������ˡ�\n");
if(random(this_player()->query_kar()) > 19 && random(100)>90)
        { 
                swo=new(__DIR__"obj/leavehook");
                swo->move(this_player());
                set_temp("mark/been_get",1);
                write("���ǽ�ϰ�����һ����𹳡�\n" );
        }
        else
        { 
                limbs=this_player()->query("limbs");
           write("������ȥ�ν�������һ��������\n");
                write("���"+limbs[random(sizeof(limbs))]+"���������ˡ�\n");
                this_player()->receive_damage("qi",random(100)+1);
                COMBAT_D->report_status(this_player(),0);
        }
        
        return 1; 
}
void reset()
{
    ::reset();
        delete_temp("mark/been_get");
}
