// Room: /d/taiwan/tangzhong 
inherit ROOM; 
 
void create ()
{
  set ("short", "������");
  set ("long", @LONG
����һ���ưܵĳ���.��Ȼˮ����Ʈ���˸�Ƽ,��������������� 
��ôǳ.���ڵĳ�ˮ��ʱ������������ǰ����,��ͷ��ˮ��������,�� 
�����ص������ж�ʯ������. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fish.c" : 2,
]));
  set("item_desc", ([ /* sizeof() == 3 */
  "����" : "����ϸ���������,�����Ϻõ���ɽʯ��̶��ɵ�.���з�ɫ 
�������и�����Ľ�ӡ. 
",
  "ʯ������" : "����ϸ���������,�����Ϻõ���ɽʯ��̶��ɵ�.���з�ɫ 
�������и�����Ľ�ӡ. 
",
  "��ӡ" : "�����ӡ��̵���������,�㿴�˿��Լ���Ь��,˼����, 
��֪�ܲ��ܲ�(touch)��ȥ. 
",
]));

  setup();
}
void init()
{ 
   add_action("do_touch","touch");
   add_action("do_climb","climb");
}
int do_touch(string str)
{
   object ob,ob1,ob2;
   ob=this_player();
   if (!ob||environment(ob)!=this_object()) return notify_fail("");
   if (!str) return notify_fail("��Ҫ��ʲô?\n");
   if (str!="��ӡ") return notify_fail("��Ҫ�������?\n");
   message_vision("$Nһ���������ϵĽ�ӡ��ȥ,ʯ����Ӧ�����³�ȥ!\n",ob);
   ob1=load_object(__DIR__"dating");
   ob2=load_object(__DIR__"midao");
if (ob1->query("exits/in")==__DIR__"midao")
     {
         tell_room(__DIR__"dating","�������е��ͻ�ͼͻȻ�����½�,���ܵ���ס��!\n");
         ob1->delete("exits/in");
         tell_room(__DIR__"midao","ǰ��ͻȻһ��ڰ�,����Ķ��ڱ���ס��!\n");
         ob2->delete("exits/out");
        return 1;
   }
   tell_room(__DIR__"dating","�������е��ͻ�ͼͻȻ������Ϣ�������ƿ�,¶��һ���ܵ�!\n");
   ob1->set("exits/in",__DIR__"midao");
   tell_room(__DIR__"midao","��ǰͻȻһƬ����,�ܵ����ڴ��ƺ��Ǹ�����\n");
   ob2->set("exits/out",__DIR__"dating");
   return 1;
}
int do_climb()
{
  object ob;
  ob=this_player();
  message_vision("$N�ֽŲ���������ȥ!\n",ob);
  tell_room(__DIR__"chitang","���˴ӳ�����ʪ��������������!\n");
  ob->move(__DIR__"chitang");
  return 1;
}
