 // Room: /d/chuenyu/trap_castle.c
#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "�е�");
        set("long", @LONG
�����ڴ���һ��խխ�ļе��ͨ�����·��һ���ʯ(rock)������
�е������������ɸߵ�ʯǽ(wall)������������ϣ�ʯǽ�ϲ�����
����Բ��(hole)��ʯǽ�ĺ��洫����֨֨�¸¡�������(noise)��
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"gate_castle",
]));
        set("item_desc", ([
  "wall" : "����һ�����ɸߣ��������ʯǽ��ǽ�ϵ�Բ�׺��ʺ�������������\n",
  "rock" : "����һ��ǧ���ʯ����ס��ͨ�����·��\n",
  "hole" : "��������Բ���￴����������̫���ˣ�ʲôҲ��������\n",
  "noise": "����Ȼ������ǿ���������\n"
])); 
        set("outdoors", "chuenyu"); 
        create_door("south", "����", "north", DOOR_CLOSED);
        set("coor/x",130);
        set("coor/y",150);
        set("coor/z",30);
        setup();
} 
void init()
{       object ob;
        if( interactive( ob = this_player()))
        remove_call_out("arrowing");
        call_out("arrowing", 15, ob);
} 
int arrowing(object ob) 
{
        int i;
        int damage;
        if( environment(ob) == this_object())
   {
        message_vision(HIW"ɲ�Ǽ�ʯǽ�ĺ��桰���ԡ������������������Բ������$N�����������\n", ob);
        message_vision("$N���Ҽ����ͷ��Ѫ�����������ˣ�\n"NOR, ob);
        i = (int)ob->query("eff_qi");
        damage = random(10)+35  ;
        ob->set("eff_qi",(int) i - damage );
        i =  (int)ob->query("qi");
        ob->set("qi",(int) i - damage);
        if( environment(ob) == this_object())
        call_out("arrowing",5, ob);     
        }
        else 
        return 1;
} 
int valid_leave(object me, string dir)
{
        remove_call_out("blowing");
        return 1;
}   
