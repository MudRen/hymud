#include <ansi.h>;
string *npc_name = ({ "��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��", }); 
mixed names = ({
        ({
        "����㳡","������","�찲��","����ϷԺ","������",
        "ɽ���س�¥","��´��Ժ","������","�Ÿ�����","½����",
        "����·","˫����","����㳡","������","������",
        "����ɽ��","�����ھ�","ɽ����","̫��","����",
        "��������","Ǯ������","������","�Ϸʹ㳡","����̲",
        "ƽ����","��۷�","ף�ڵ�","��������¥","������",
        "������","������","ƽ��ʯ","��Ԫ��","����¥",
        "ţ�Ҵ��","��ͻȪ","������","��ʥ��","������Ժ",
        "�ػ���","�껨̨","��ң��","®ɽ","���⸮",
        "Ұ����","������ɽ��","�̼���","��紨","һƷ�ô���",
        "������","������","���س�����","�������","��ľ��Ӫ��",
        "��΢��","���ľ�","�����","��������","����ɽ",
        "פ��ׯ","�Խ���","ʩ�Ž�����","���ݳ�","���ֹ㳡",
        "������ɲ","���и�","�����","��ɽ��","���",
        "����","��ʥ����","«έ��","�����","�չ���",
        "���Ҵ���","�簲��","���Ĺ�","��������","���ƺ",
        "��翷�ɽ��","����ɽ","ʥ��","ܽ�ؿ�ջ","�����",
        "С��Ĺ","�㽫̨","�����ھ�","���ݹ�Ժ","���Ĺű�",
        "�Ž��㳡","ȫ�۵¾�¥","��³��","������","�����ַ�",
        "��������","��Զ","ɽ����","����ͷ","����Ժ",
        }),
        });
string ask_fangqi()
{
         object me;
object obj;
         me = this_player();
         if(me->query_condition("husong_busy")<=1)
         return "��û��������,������Ϲ����ʲ��?";
         me->clear_condition("husong_busy");
         if (me->query("combat_exp",1) > 300) me->add("combat_exp",-200+random(20));
         me->apply_condition("zzz_busy",18);
         me->apply_condition("menpai_busy",18);
         me->apply_condition("hu_song",0);
         me->clear_condition("hu_song");
         me->delete_temp("hu_song");
if (obj=present("gong zi",environment(me)))
{
if(obj->query_temp("host")==me->query("id"))
{
destruct(obj);
}
}
         return "û��ϵ,�´μ���Ŭ�� ��";
}

string ask_job()
{     object wang,ob;
      object *team;
          int i=0,count=0,minexp,maxexp;
      string where;
          wang =this_object();
          ob=this_player();
          
  if (!wizardp(ob) && interactive(ob) && (int)ob->query_condition("zzz_busy"))  
       return ob->query("name")+"����²������ȵȻ�ɡ�";

  if (!wizardp(ob) && interactive(ob) && (int)ob->query_condition("guojob2_busy"))  
       return ob->query("name")+"�����ҿ�û�и�������񣬵Ȼ������ɡ�\n";

       if (!wizardp(ob) && (int)ob->query_condition("menpai_busy"))  
       return "�����Ǽ�Σ�չ������ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
//        if (ob->query_condition("husong_busy"))
//        return "������û�и��������";//husong busy time 
          
  if (!wizardp(ob) && interactive(ob) && ob->query_temp("hu_song")
      && (int)ob->query_condition("husong_busy"))  
       return ob->query("name")+"����һ�ε�����û���!";
          if(ob->query("combat_exp")<5000000 && ob->query("jobtime")!=6)
      return  ob->query("name")+"��Ĺ���̫���ˡ�";//too low exp

          if(ob->query_skill("force",1)<100)
      return  ob->query("name")+"��Ĺ���̫���ˡ�";//too low exp

      team=ob->query_team();
      count=sizeof(team);
      if(count>=5)
          return "���²������"; //too many people
          minexp=ob->query("combat_exp");
          maxexp=minexp;
      
          for(i=1;i<count;i++)
      { if(team[i]!=0)
          {
                if(team[i]->query("combat_exp")<minexp)
            minexp=team[i]->query("combat_exp");
                if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
          }
          }
          if ((maxexp-minexp)>800000)
      return "���ǵ��书���̫���⡣";//exp too far
     //check ok
     // ob->set_temp("team_count",count);
          ob->apply_condition("husong_busy",60);
          for(i=0;i<count;i++)
          {if(team[i]!=0)
           team[i]->apply_condition("husong_busy",60);
           team[i]->set_temp("hu_song",1);
          }
         // for(i=100;i*i*i/10<=maxexp;i++);
         i=ob->query_skill("force",1);
      where=names[0][random(sizeof(names[0]))];
          call_out("make_npc",0,i,ob,where,count);
          message_vision(HIY"\n$N�ӻ��֣�һλ���Ӵ������������˹�����\n"NOR,this_object());
          command("say "+ob->query("name")+"����Ұ���λ���ӻ��͵�"+where+"��");
          ob->set_temp("hu_song",1);
          ob->apply_condition("menpai_busy",8);
          ob->start_busy(2);
          return ob->query("name")+"��ȥ�ٻأ�һ·�϶��С�ġ�";   
}

void make_npc(int maxpot,object player,string where,int count)
{   object obj;
//        player->start_busy(3);
//      player->set("hu_song",1);
        player->set_temp("hu_song",1);
        obj = new(__DIR__"gongzi");
    obj->move(environment(player));
    player->set_temp("hstarget",where);
        obj->set_temp("target",where);
        obj->set_temp("maxpot",maxpot);
    obj->set_temp("count",count);
     obj->set_name(player->query("name")+"���͵�"+npc_name[random(sizeof(npc_name))]+"����", ({player->query("id")+" gz","gong zi"}));
        obj->set_temp("host",player->query("id"));
        obj->set_leader(player);
        message_vision("$N��������$nһ���ж���\n",obj,player);
        player->apply_condition("hu_song",100);
        return;

}    

