
// sp_beggar.c

#include <ansi.h>
inherit NPC;

int get_order(object me);
void create()
{
        set_name("��ؤ", ({ "begger" }) );
        set("gender", "����" );
        set("age", 53);
        set("long", "һ��������˪֮ɫ������ؤ����������˫Ŀ�ر�����\n");
        set("combat_exp", 100);
       
        set("kee", 0);
        set("max_kee", 1);
        set("str", 27);
        set("force", 0);
        set("max_force", 0);
        set("force_factor", 0);
        set("max_atman", 10000);
        set("atman", 10000);
        set("inquiry", ([
                "��ͼ" :  (: get_order :),
                "��Ƥ��ͼ" :  (: get_order :),               
  "���µ�ͼ" :(: get_order :),
                         ]));
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
             "��ؤ˵�������ĵĴ�ү�ġ� ����Ҫ���ļ�������ͷ�ɡ�\n",
                "��ؤ������ش��˸���Ƿ��\n",
                
"��ؤ����׽ס�����ϵ�ʭ�ӣ��������������û�����⣬ȫ�����Ǹ�ҧ���ˡ� \n",
        }) );
}
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"������С������뿪��\n");
        return 0;
}
int get_order(object me)
{
if (!this_object()->query("get_his_name"))
{                 command("say �������������ڣ�����20������ͷ����!!");
    this_object()->set("get_his_name",this_player()->query("id"));
              this_player()->set("get_time", (int) time()+60);
          this_object()->set("get_time", (int) time()+90);
                  return 1;         }
 command("say �����ڲ���Ҫ���ʲô��!");
      return 1;
             }

int accept_object(object who, object ob)
{     object map;        
      if (ob->query("id")=="bone"
      && who->query("id") == this_object()->query("get_his_name"))
          { this_object()->add("i",1);
            if (this_object()->query("i") == 20) 
                  { if (who->query("get_time")>(int)time())
                   { map=new("open/tony/jjf/obj/map7.c");
                    map->move(who);
                    this_object()->set("i",0);
this_object()->delete("get_his_name");
                    command("say ��ȥ�ɣ��Ҿ�ʣ��������");
                call_out("leave", 1);
                    return 1;
                    }         
                   else
                      {command("say ����̫���ˣ���ͼ�������ˣ�");
                    this_object()->set("i",0);
                           return 1;} 
                   }           
  
               return 1;}
         else {command("say �Ҳ�Ҫ");
                return 0;} 
}
int heal_up()
{
if (!this_object()->query("get_his_name")
|| this_object()->query("get_time")>(int)time())

{return ::heal_up() + 1;
}
     else{   this_object()->set("get_time",0);
       this_object()->delete("get_his_name");
                call_out("leave", 1);
           }            
}

void leave()
{       object *room;
        int i,k;
        message("vision",
   NOR + name() + " ����һ����磬�����ˡ�\n" NOR, environment(),
               this_player() );
        room = objects( (: function_exists("create_door", $1) :) );
        i = sizeof(room);
        k = random(i);
      this_object()->move(room[k]);
}
