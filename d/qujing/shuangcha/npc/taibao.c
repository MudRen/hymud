//Cracked by Roath


inherit NPC;
#include <ansi.h>
int do_ok(string arg);
#include <obstacle.h>

int do_tell ();
void create()
{
        set_name("������", ({"liu boqin","liu"}));
        set("gender","����");
        set("age",30);
        set("title",HIY"��ɽ̫��"NOR);
        set("long","ɽ�е�һ���Ի���ʮ�ֵĴ�׳��");
        set("per", 20);
        set("str", 50);
        set("dex", 350);
        set("attitude","friendly");
        set("combat_exp",1000000);
        set("max_neili",10000);
        set("neili",10000);
        set("force_factor",40);
        set("max_qi",30000);
        set("qi",30000);
        set("jing",30000);
        set("max_jing",30000);
        set_skill("unarmed",380);
        set_skill("parry",380);
        set_skill("staff",300);

        set("inquiry",([
                "��ɽ̫��" : "��ɽ̫�������Ұ���",
                "here": "����ط�����˫����",
    "����" : (: do_tell :),
    "����" : (: do_tell :),
    "��ȡ�澭" : (: do_tell :),
    "ȡ��" : (: do_tell :),
    "�澭" : (: do_tell :),
    "��" : (: do_tell :),
                ]));
        setup();

        carry_object("/d/obj/cloth/luoyi2")->wear();
        carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

void init()
{
        object ob = this_player();
        remove_call_out("check");
        call_out("check",1,ob);
        add_action("do_ok","ok");
        add_action("do_ok","answer");
}
void check(object ob)
{
        if( this_object()->query("said") ) return ;
        if( environment()->query("short") == "ɽ��" && ob->query_temp("tiger_kill")=="yes")
        {
        command("say ��λ....����������������ɽ̫��Ҳ���簡��");
        command("say �粻���������Ҽ�һ�����(yes)�� ");
        this_object()->set("said",1);
        }
        return ;
}
int do_ok(string arg)
{
        object me = this_player();
        object ob = this_object();
        
   if(!me->query_temp("tiger_kill"))
	return 0;
   if( me->query("obstacle/sc") == "done"||me->query("obstacle/jz") != "done")
        {
        command("say �һ��е����顣\n");
        command("hehe");
        call_out("des",1,ob);
          return 0;
        }
         if( me->query("obstacle/jz") == "done")
        {
        command("say �ðɣ��������߰ɡ�");
        me->set_temp("sc/taibao_seen",1);
        
        me->move("/d/qujing/shuangcha/shanlu4");
        ob->move("/d/qujing/shuangcha/shanlu4");
        message_vision(HIR "$N����������ɽ�����˹�����"NOR,me);
        me->move("/d/qujing/shuangcha/shanlu5");
        ob->move("/d/qujing/shuangcha/shanlu5");
        message_vision(HIR "$N����������ɽ�����˹�����"NOR,me);
        me->move("/d/qujing/shuangcha/enter");
        ob->move("/d/qujing/shuangcha/enter");
        message_vision(HIR "$N�����������ǰ���˹�����"NOR,me);  
        me->move("/d/qujing/shuangcha/gate");
        ob->move("/d/qujing/shuangcha/gate");
        message_vision(HIR "$N����������������˹�����"NOR,me);  
        me->move("/d/qujing/shuangcha/yard");
        ob->move("/d/qujing/shuangcha/yard");
        message_vision(HIR "$N����������ͥԺ���˹�����"NOR,me);
        me->move("/d/qujing/shuangcha/yard");
        ob->move("/d/qujing/shuangcha/yard");
        message_vision(HIR "$N����������ͥԺ���˹�����"NOR,me);
        me->move("/d/qujing/shuangcha/zhengting");
        ob->move("/d/qujing/shuangcha/zhengting");
        message_vision(HIR "$N����������������˹�����\n"NOR,me);
        command("say �Եȣ����ҳ�ȥһ�ᡣ");
        destruct(ob);
        me->set_temp("home",1);        
	me->delete_temp("tiger_kill");
        return 1;
        }
}
void des()
{
        destruct(this_object());
}



int do_tell ()
{
  call_out ("telling",1,this_player());
  return 1;
}

int telling (object who)
{
  object me = this_object();

  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *strs = allocate (size);
  int nb = 0;
  int i;

  if (!objectp(who)) return 0;
  for (i = 0; i < size; i++)
  {
    strs[i] = "none";
  }

  for (i = 0; i < size; i++)
  {
    if (who->query("obstacle/"+names[i])=="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }

  if (nb == 0)
  {
    tell_object (who,me->query("name")+"�����㣺����δ������ȡ�澭��\n\n");
  }
  else
  {
    tell_object (who,me->query("name")+"�����㣺��������ȡ�澭�ѹ���"+
                     chinese_number(nb)+"�أ�\n");
    who->set("obstacle/number",nb);
    who->save();
    strs = (string *)sort_array (strs, 1);

    for (i = 0; i < nb; i++)
    {
      tell_object (who,"    "+strs[i]+"\n");
    }

    tell_object (who,"\n");
  }



  return 1;
}

