 // XXDER@fy
inherit ROOM;
#include <command.h>
#include <ansi.h>
void create()
{
        set("short", "������");
        set("long", @LONG
�㷢���������Ծ��������ϻ����ϣ�����������Ҳ͸����ï�ܵ����ڡ���ǰ��
���������ؿ����˴���Ӿ�ס��Ժ�䣬�������������԰���г������������
�۵ף�������һ���������Ĳ���û��С·��֪ͨ��η���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "down" : __DIR__"garden",
   ])); 
   set("item_desc", ([
   "treetop" : "����ï�ܵ�ʹ�㿴������գ�����Լ�����������ƺ���һ��ں����Ķ�����\n",
   "����" : "����ï�ܵ�ʹ�㿴������գ�����Լ�����������ƺ���һ��ں����Ķ�����\n",
   ]) );
        set("coor/x",170);
        set("coor/y",2000);
        set("coor/z",10);
        setup();
} 
void init()
{
   add_action("do_climb", "climb");
} 
int do_climb(string arg)
{
   object me, room;
   int mlvl;
   
   me = this_player();
   if(!arg || arg != "�ϻ���" && arg != "tree") return 0; 
   mlvl = (int)me->query_skill("move");
   if(mlvl < 70)
      message_vision("$Ņͷ���������������ﲻ�ɵ���Щ���š�\n", me);
   else{
      message_vision("$N����������������ȥ��\n", me);
      room = find_object(__DIR__"treetop");
      if(!objectp(room)) room=load_object(__DIR__"treetop");
      me->move(room);
   }
   return 1;
}
