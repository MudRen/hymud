// Room: /d/taiwan/mishi
inherit ROOM;
int have_sword=1;
void create ()
{
  set ("short", "����");
  set ("long", @LONG
һ�����ʯ���ɵķ���,�ıڵ�������ϵ��¸�����ħ,һ����Ȫ�� 
�ڶ�������,����ʯ���м��һ���ķ�ˮ��(chi)��.�ص����ܲ��žŰѽ� 
����һ�ѿ���ȥ�ر�ĳ���. 
LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "chi" : "��ˮ���峺,����㼢�ʵĻ�,�����ȼ���. 
        (drink water) 
",
  "��" : "�Űѽ�ʽ�����Բ�ͬ,���а˰Ѷ��������ĵĹ�,һ����֪������� 
����,ֻ���м��һ��,ȴ�ڳ�����һ�㲻����,��֪�ܲ��ܰ�����. 
         (ba sword) 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"boss",
]));
set("valid_startroom",1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/master.c" : 1,
//	"/obj/money/gold.c" : 2,
]));

  setup();
}
void init()
{
   add_action("do_drink","drink");
   add_action("do_ba","ba");
}
int do_drink(string sss)
{
object ob;
ob=this_player();
if ((sss!="chi")&&(sss!="shui")&&(sss!="water"))
  {
   return 0;
  }
if(ob->query("water")> ((int)ob->query("str")-10)*10+150 )
 {
  tell_object(ob,"������˻�Ҫ�Ȱ���\n");
  return 1;
 } 
else
 {  
 say(ob->query("name")+"ſ��ˮ�رߣ�һ�������˹���. \n");
 tell_object(ob,"��ſ��ˮ�رߣ�һ�������˹���. \n");
 ob->set("water",((int)ob->query("str")-10)*10+200);
  return 1;
 }
}
int do_ba(string str)
{
   object ob,ob1;
   ob=this_player();
   if (!ob||environment(ob)!=this_object()) return 0;
   if (str!="sword") return 0;
   if (have_sword==0)
    {  tell_object(ob,"���Ͽտ���Ҳ,���������Ѿ�����������!\n");
       return 1;
    }
  ob1=present("dongming zi",this_object());
  if ((ob1)&&(ob->query("family/family_name")!="��ڤɽׯ"))
  {
     message_vision("$N���һ��:���ҿ�̽�����֮��,ȥ������!\n",ob1);
     ob1->kill_ob(ob);
     return 1;
  }
if (ob->query("str")<21)
{  message_vision("$Nץס����,�����ε��������,����һ������!\n",ob);
   return 1;
}
message_vision("$N���ְν�,���һ��:[��],һ�ѳ���Ӧ���Ƶض���!\n",ob);
clone_object(__DIR__"obj/youming")->move(ob);
have_sword=0;
return 1;
}
