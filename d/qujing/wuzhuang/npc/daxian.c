// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// zhenyuan.c...weiqi, 98.02.24.
// copied a lot of useful functions from "rulai.c"...thanks snowcat:)

#define DEBUG 0

inherit NPC;
inherit F_MASTER;
#include "/d/migong/romnpc2.c"
string expell_me(object me);
string keyword(object me);
string sword_xiaofeng(object me);
string sword_sanqing(object me);
string asked_guo(object me);
string ask_mieyao(object me);
string ask_cancel();

void create()
{
   set_name("��Ԫ����", ({"zhenyuan daxian", "zhenyuan", "daxian"}));
   set("title", "��ׯ�۹���");
   set("gender", "����" );
   set("age", 65);
   set("per", 24);
   set("str", 30);
   set("long", "���α����磬���������С���һλ����֮�棡\n");
   set("class", "xian");
   set("combat_exp", 5600000);
   set("attitude", "peaceful");
   create_family("��ׯ��", 1, "��ʦ");
   set("rank_info/respect", "����");
   set_skill("unarmed", 180);
   

   set("max_qi", 4500);
   set("max_jing", 4500);
   set("neili", 5000);
   set("max_neili", 2500);
   set("neili", 7000);
   set("max_neili", 3500);   
   set("force_factor", 200);
   set("mana_factor", 200);

   set("spell_qiankun_on", 1); //to use cast qiankun, must set this.


   set("inquiry", ([

     "name": "�Ϸ���Ԫ��\n",
     "here": "��������ׯ�ۣ�����ס�Ŀɲ��ǵ�ʿ��\n",
 
  

   ]) );

   setup();
   initlvl((300+random(280)),16);
   carry_object("/d/obj/cloth/xianpao")->wear();
   carry_object("/d/obj/weapon/sword/ruler")->wield();
}







void init()
{
        
     object ob = this_player();
        if( ob->query_temp("kill_tree") )
        {
        command("say С��ë����������ҵ��˲ι����Ȼ����Ϸ򲻿����ˡ�");
        command("slap "+ob->query("id"));
        }

}

int do_true(string arg)
{
   if(this_player()->query_temp("asked_leave_wzg")) {
     message_vision("$N��������������ף�\n\n", this_player());
     message_vision("��Ԫ����̾�˿��������ã��������ǿ͡�\n", this_player());
     this_player()->add("betray/wuzhuangguan", 1);
     this_player()->add("betray/count", 1);
     this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
     this_player()->delete_skill("taiyi");
     this_player()->delete("family");
     this_player()->set("faith",0);
     this_player()->delete("class");
     this_player()->set("title", "��ͨ����");
     this_player()->delete_temp("asked_leave_wzg");
     this_player()->save();
     message_vision("˵����$Nͷ��һ����$Nֻ������һ�ᣬ�յ����غ�����ʲô��\n", this_player());
     return 1;
   }
   return 0;
}

//the following is for renshen dahui...

void announce (object me, string str)
{
   if (DEBUG)
   { 
     object weiqi = find_player ("weiqi");
     if (weiqi && wizardp(weiqi))
        tell_object (weiqi,"�� "+str+"\n");
   }
   else
   {
     CHANNEL_D->do_channel(me,"chat",str);
   }
}

void start_renshen()
{
   object me;

   me = this_object();
    
   set_temp("invite","public");

   announce (me, "��ׯ���˲ι�Ʒ����ἴ����ʼ��\n");
   announce (me, "��λ������Ը����ʹaccept zhenyuan daxian��ɣ�\n");
   remove_call_out ("inviting");
   call_out ("inviting",1,me);

   call_out("ready1", 180);
   set_temp("ready0", 1);
}

void ready1()
{
   object me;

   me = this_object();

   announce (me, "��ׯ���˲ι�Ʒ��������Ͼ�Ҫ��ʼ��\n");
   announce (me, "��λ������Ը����ʹaccept zhenyuan daxian��ɣ�\n");
   call_out("ready2", 180);
   set_temp("ready1", 1);
}

void ready2()
{
   object me;

   me = this_object();

   announce (me, "��ׯ���˲ι�Ʒ��������ڿ�ʼ��\n");
   announce (me, "��λ������Ը����ʹaccept zhenyuan daxian��ɣ�\n");
   set_temp("ready2", 1);
}

string asked_guo(object me)
{ 
   int i, total;
   object guo;
   object *inv ;
      
   me=this_player();

   //if no renshenguo party at all...
   if( query_temp("ready0") != 1 ) return ("�˲ι����Ǹ��ö�����\n");

   //if not in the right place, no guo...
   //need the right name, also right outdoors(so ppls can not use fake room).
   if( (environment(this_object()))->query("short") != "�˲ι�԰" || 
     (environment(this_object()))->query("outdoors") != "wuzhuang" )
   {
     return ("�����ֲ��ǹ�԰���������˲ι���\n");
   }

   //if waiting for ppls...
   if( query_temp("ready1") != 1 ) return ("��Ҫ�����ٵȵȡ�\n");

   //if ready to begin...
   if( query_temp("ready2") != 1 ) return ("��Ҫ�������Ͼ��С�\n");

   //if finished...
   if( query_temp("finished") == 1 ) return ("�˲ι��ѷַ����ˡ�\n");

   //now check how many people here...
   total = 0;
   inv = all_inventory( environment(this_object()) );
   for(i=0; i<sizeof(inv); i++)
   {
     if( userp(inv[i]) && (!wizardp(inv[i]))  ) total++;
   }

   if( total > 3 ) return ("��ѽ����ô���ˣ�����ֻ����ö������˲ι���\n");
   else if ( total <= 3 && total > 0 )
   {
     for(i=0; i<sizeof(inv); i++)
     {
        if( userp(inv[i]) && (!wizardp(inv[i]))  ) 
        {//wiz not counted...
          guo = new("/d/obj/drug/renshen-guo");
          guo->move(inv[i]);
          message_vision("$N��$nһö�˲ι���\n", this_object(), inv[i]);
          announce (this_object(), "��ϲ��ϲ��" + inv[i]->query("name") + "����˲ι�һö��\n");
        }
     }

     set_temp("finished", 1);
     call_out("finishing", 5);

     return ("�ã��˲ι��ַ���ϣ���λ���;������ðɡ�\n");
   }
   else return ("˭Ҫ�˲ι���\n");
   
}

void finishing()
{
   message_vision("$N������Ц��������ʱ��Ӱ�����ˡ�\n", this_object());
   delete_temp("invite");//this is necessary if not going to destruct this obj.
   destruct(this_object());
}

void inviting (object me)
{
   int i;
   object *list;

   if (! me->query_temp("invite"))
   return;
  
   remove_call_out ("inviting");
   call_out ("inviting",4+random(4),me);

   list = users();
   i = sizeof(list);
   while  (i--)
   {
     string here, there;

     reset_eval_cost();
    
     if (!environment(list[i]))
        continue;
    
     if (environment(list[i])->query("unit")) // not a room
        continue;
   
     if (list[i]->is_fighting())
        continue;
    
     if (list[i]->is_busy())
        continue;
    
     if (list[i]->query_temp("no_move"))
        continue;
    
     if (!living(list[i]))
        continue;
    
     if ((string)list[i]->query_temp("accept")!=me->query("id"))
        continue;

     list[i]->set_temp("accept",0);
     here = (string)environment(me);
     there = (string)environment(list[i]);
     if (here == there)
        continue;

     message_vision("$N�Ĵ�������һ�֡�\n",me);
     list[i]->set_temp("accept",0);
     list[i]->set_temp("wzg/from",there);

     message_vision("һ������Ʈ�����������һֻ�޴�����佫$N����һ�֣���ʧ����ա�\n",list[i]);
         list[i]->move(here);
     message_vision("��$N��������һ����$n���˳�����\n",me,list[i]);
     break;
   }
}

int do_back(string arg)
{
   object who = this_player();
   object me = this_object();
   string here = (string)environment(me);
   string there = who->query_temp("wzg/from");

   message_vision("$N����$n��$N�ط���\n",who,me);
 
    //if (!there)
   // there = "/d/city/kedian";
   there = "/d/city/kedian";

   who->set_temp("accept",0);
   message_vision("$N�Ĵ��䳯��$n����һ�֡�\n",me,who);
   who->move(there);
   message_vision("���������һֻ�޴����������һ����ֻ��$N�����滬�˳�����\n",who);
  
   return 1;
}


