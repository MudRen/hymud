// Room: /d/taiwan/chufang.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
һ���ª�ĳ���,ľ����ס�Ĵ����ϸ�֩�����˸���.һ�����õ����� 
���ڷ����Ƕ�,һ������ɫ��ľ���뿪��,�ܿ����������յ.��ֻ����� 
�������æ���ӿ���. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/table.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"huilang.c",
]));

  setup();
}
void init()
{
      if (interactive(this_player()))
             {  remove_call_out("greeting");
                 call_out("greeting",15,this_player());
             }
}
void greeting(object me)
{
    object ob1;
    int i;
    if (!me) return;
    if (environment(me)!=this_object()) return;
        ob1=present("zhizhu",this_object());
         if (!ob1)
            {  i=me->query("kar");
            if (random(i)<15)
                 {
message("vision","������һ��Ϥ������,��̧ͷ��ʱ,һֻ֩������ϵ�������!\n",__DIR__"chufang");
                        ob1=new(__DIR__"npc/zhizhu");
                        ob1->move(this_object());
                        return;
                 }
message("vision","��������������ϤϤ����������,��ϸ������ȴһ������!\n",__DIR__"chufang");
          return;
        }
   return;
}
