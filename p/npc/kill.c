// migong lev12  ���ǽ� ������

#include <ansi.h>

inherit NPC;
#include "/quest/menpai/romnpc.c"
#include "/quest/menpai/givegift.c"
string* names = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�",
"ξ��","����","�̨","����","����","���","����","����","̫��",
"����","����","����","ԯ��","���","����","����","����","Ļ��",
"˾ͽ","ʦ��","��","��ľ","����","����","���","����","����",
"����","��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��",
"��ǧ","����","����","�Ϲ�","����","�麣","����","΢��","����",
"����","����","����","����","�Ϲ�",

"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��","��",
"��","ʯ",
});

string* nm2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","ǿ","��","ɽ",
"̩","��","ͦ","ΰ","��","��","��","��",
"��","�","��","��","��","��",
});


void create()
{
  
       int i = random(sizeof(names));
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], 
 ({ "sha shou"  }));
 
set("title", RED"����ɱ��"NOR);
 
 if (random(2)==0)
   set("gender", "����" );
 else set("gender", "Ů��" );
 set("long",
"�书��ǿ���ĺ�����������ɱ�֡�\n");

set("isteamjob",1);
  set("max_qi",6000+random(3000));
  set("max_jing",6000+random(3000));
  set("max_sen",3000+random(3000));
  set("max_neili",13000+random(3000));
  set("max_mana",3000+random(3000));
  set("eff_neili",13000+random(3000));
  set("neili",3000+random(3000));

        set("age", 14+random(30));

       set("jiali" , 100);

        set("no_get",1);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 1000000);
            if (random(20)==0)
{
            set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
           set_temp("apply/armor", 1200);
        set_temp("apply/damage", 1200);
 }       


        setup();
initlvl(200+random(180));
	


}



void init()
{
        remove_call_out("leave");
        call_out("leave",300);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
int do_back(object me)
{                       
        me = this_object();
  tell_room(environment(me), me->query("name")+"�Ҵ�ææ���뿪�ˡ�\n", ({me}));	
  destruct(me); 
  return 1;
}


void die()
{
int i,pot,exp;
	object killer;
	exp= random(88)+88;
	pot= exp*2/3+1;
	if(objectp(killer = query_temp("last_damage_from")))
{
addnl(killer,"exp",exp);
}
	::die();

return ;
}