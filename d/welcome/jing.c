#include <ansi.h>
inherit NPC;

string ask_liwu();
string ask_liwu1();
string ask_liwu2();
string ask_liwu3();
string ask_liwu4();
string ask_liwu5();
string ask_liwu6();
string ask_liwu7();
string ask_liwu8();
string ask_liwu9();
string ask_liwu10();
string ask_liwu11();
string ask_liwu12();
string ask_liwu13();
string ask_liwu14();
string ask_liwu15();
string ask_liwu16();
#include "/quest/givegift.c"
void create()
{
        set_name("�ϴ峤", ({ "lao cunzhang","lao" }) );
  set("title", HIM "��ʦ���˼��˰���" NOR);
	set("gender", "����" );
	set_temp("no_kill", 1);
	set("age", 76);
	set("per", 100);
        set("long", "����һ����С�����ߣ���������һ�ٶ��꣬���Ǳ�Ϸ�ӱ����
���͵�ʦ����Ҳ��������ִ�Ĵ峤���������ʲô���ⲻ��
������æ������ָ�� ask lao about here �ɵõ�������Ϣ��\n");
	set("shen_type",1);
	set("combat_exp", 2000000);
	set("attitude", "peaceful");
        set("apply/attack", 350);
	set("apply/defense", 350);

	set_skill("unarmed", 1500);
	set_skill("blade", 1500);
	set_skill("parry", 1500);
	set_skill("dodge", 1500);
	set("inquiry" , ([
             "here" : (: ask_liwu :),
             "����" : (: ask_liwu :),
             "out" : (: ask_liwu14 :),
             "����" : (: ask_liwu14 :),
"����" : (: ask_liwu15 :),
"job" : (: ask_liwu15 :),
"ok" : (: ask_liwu16 :),
"����" : (: ask_liwu16 :),
	     "1" : (: ask_liwu1 :),
	     "2" : (: ask_liwu2 :),
	     "3" : (: ask_liwu3 :),
	     "4" : (: ask_liwu4 :),
	     "5" : (: ask_liwu5 :),
	     "6" : (: ask_liwu6 :),
	     "7" : (: ask_liwu7 :),
	     "8" : (: ask_liwu8 :),
	     "9" : (: ask_liwu9 :),
	     "10" : (: ask_liwu10 :),
	     "11" : (: ask_liwu11 :),
	     "12" : (: ask_liwu12 :),
	     "13" : (: ask_liwu13 :),
	]));

	setup();
	carry_object("clone/cloth/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {

			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		
	}


}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

			say( HIG"�ϴ峤����˵������λ" + RANK_D->query_respect(ob)+ "�������Ҫ����������ָ�� "+HIR+"ask lao about here\n"NOR);


}


string ask_liwu()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->add_temp("nbjob1",1);
if (me->query_temp("nbjob1",1)>2) me->set_temp("nbjob1",2);
msg=HIY"\n���         ��    Ϣ
 1        ʲô������MUD��Ϸ
 2        �򵥽���һ�������Ϸ���淨
 3        ������Ϸ������Щʲô
 4        ���Լ���˭
 5        ��������
 6        ����ƶ�
 7        ��θ��������ѽ���
 8        �ҿ��԰�����Щ��ɫ
 9        �������
10        ���������ʹ�ñ���
11        ���ս��
12        ��εõ��������
13        ����뿪���ﵽ���������ȥ
Ҫ�˽����Ϣ��������ָ�� "HIR"ask lao about <���>"NOR"
��Ҫ�˽� <����ƶ�> ����Ϣ�������� "HIR"ask lao about 6"NOR"
�������λ����ң������"HIR"ask lao about job"NOR"����ʼ������ֽ̡̳�
�������λ����ң���Ҳ����ֱ��"HIR"ask lao about ����"NOR"��ȥ������������Ȼ�����Ļ�����ܻ��ʧ��ĳ�ֻ�Ե��"NOR;
  return msg;
}

string ask_liwu1()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"1") );
  return "����IV ��ӭ��";
}

string ask_liwu2()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"2") );
  return "����IV ��ӭ��";
}
string ask_liwu3()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"3") );
  return "����IV ��ӭ��";
}
string ask_liwu4()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"4") );
  return "����IV ��ӭ��";
}
string ask_liwu5()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"5") );
  return "����IV ��ӭ��";
}
string ask_liwu6()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"6") );
  return "����IV ��ӭ��";
}
string ask_liwu7()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"7") );
  return "����IV ��ӭ��";
}
string ask_liwu8()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"8") );
  return "����IV ��ӭ��";
}
string ask_liwu9()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"9") );
  return "����IV ��ӭ��";
}
string ask_liwu10()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"10") );
  return "����IV ��ӭ��";
}
string ask_liwu11()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"11") );
  return "����IV ��ӭ��";
}
string ask_liwu12()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"12") );
  return "����IV ��ӭ��";
}

string ask_liwu13()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;


msg=HIY"���������������ϸ�����ָ�� "HIR"ask lao about ����"HIY"����\n�ɵ����Ŵ塻���ȥ�һ���������ָ�� "HIR"ask hua about ����"NOR"����"NOR;



  return msg;

}

string ask_liwu14()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;
  int exp,pot;

if (me->query("nbjob",1)==19)
{
  exp=18888;
  addnl(me,"exp",exp);	
me->set("nbjob",20);
}
me->set_temp("isout",1);

if (me->query("nbjob",1)!=20 || !me->query("nbjob",1))
{
me->set_temp("isout",1);
  return "����Գ�ȥ���������ˣ�����û�������������(ask lao about job) ���ֽ���������ʧ����ע�⣡ȥ����(west)�һ�����! ";
}

  return "���������������Ѿ����Գ�ȥ���������ˣ�ȥ����(west)�һ�����!";
}             


string ask_liwu15()
{
  string msg;
  object ob1;
  object me=this_player();
  int exp_bound,qn_bound,neili;
if ((int)me->query("combat_exp",1)==0) me->set("nbjob",0);

msg="�������Ѿ����Գ�ȥ���������ˣ� ask lao about ����";
if (!me->query("nbjob"))
msg=HIY"�ϴ峤˵����\n��һ������
  �鿴���ְ��� ������
  ask lao about here 
  help newbie
  ��ɺ� ask lao about ok"NOR;

if (me->query("nbjob",1)==1)
{
msg=HIY"�ϴ峤˵����\n�ڶ�������
  �ҽ�����һЩ����д�ֺͽ������鿴���״̬ ������
  hp,score,skills,verify feixian-sword
  ��ɺ� ask lao about ok"NOR;
if (!me->query_skill("literate"))
{
me->set_skill("literate",10);
}
if (!me->query_skill("feixian-sword"))
{
me->set_skill("feixian-sword",5);
}
}


if (me->query("nbjob",1)==2)
msg=HIY"�ϴ峤˵����\n����������
  ��·�����䳡��Ϣ�� ������
  e,e,s,sleep
  ��ɺ� ask lao about ok"NOR;

if (me->query("nbjob",1)==3)
msg=HIY"�ϴ峤˵����\n���ĸ�����
  ȥҪ��ͷ��ˮ��Ȼ�����ų������ǡ�������
  east,north,yao
  �����Ҫ�����ǣ�����eat mantou,drink water
  ��ɺ� ask lao about ok"NOR;
  
if (me->query("nbjob",1)==4)
msg=HIY"�ϴ峤˵����\n���������
  ��ʦѧ�书 ���ҵ��������� �䲮(Wu bo)
  �鿴ʦ��������ʹ�� skills ʦ��ID skills wu bo 
  Ȼ��bai wu bo 
  ��ɺ� ask lao about ok "NOR;
  
if (me->query("nbjob",1)==5)
msg=HIY"�ϴ峤˵����\n����������
  ѧϰ�䲮��10����������(sword)��10��������ɣ�feixian-sword����ʹ��(enable sword feixian-sword)
  ���ҵ��������� �䲮(Wu bo) 
  Ȼ����learn|xue <ĳ��> <����> <����>
  ��������ѧϰ�� ������s��˯��(sleep) 
  �Ѿ�ѧϰ�����ڹ������ڹ� �루jifa force �����ڹ��� ��ʹ�� ��yun regenerate�� �����ָ�����
  ��ɺ� ask lao about ok"NOR;
  
if (me->query("nbjob",1)==6)
msg=HIY"�ϴ峤˵����\n���߸�����
  ȥ��һ�ѽ�����װ�� (wield sword)
  ���Ե��ӻ���ȥ��(buy)����ȥ��������һ��(qu)
  С��ʾ�����䲮�� n ������������  
  ����֮�� e s ������ӻ��̿��Թ���(list �鿴)
  ��ɺ� ask lao about ok"NOR;

if (me->query("nbjob",1)==7)
msg=HIY"�ϴ峤˵����\n�ڰ˸�����
  �þ��� ������� ɱһ֧Ұ��
  �ҵ�Ұ�� Ȼ��kill 
  ʹ�þ���perform feixian
  ʹ�þ�����Ҫ�ڹ�(force) ����������ѧ�����ڹ���һ���ڹ�������(dazuo) ���5��������
  С��ʾ �䲮������ѧϰ�����ڹ�(force)�������ڹ�(jingyiforce) ѧϰ��10��(jifa force �����ڹ�) 
  �õ�ǰ��(hp �鿴) ����������5���������(dazuo ��ǰ��)
  ��ɺ� ask lao about ok"NOR;

if (me->query("nbjob",1)==8)
msg=HIY"�ϴ峤˵����\n�ھŸ����� 
  ���һ��ϴ��������
  �ҵ�����Ŀ͵� �鿴��ͼ��ʹ��mapָ�� ʹ��set showmap 1 ���Կ�����ǰ��ͼ
  ��ʾ:e,e,e,n,ask xiao er about job Ȼ��west,ask guan shi about panzi
  east,north,xi zangpanzi��� ������ʾ��,south,give panzi to xiao er
  ��ɺ� ask lao about ok"NOR;            
   

if (me->query("nbjob",1)==9)
msg=HIY"�ϴ峤˵����\n��ʮ������ 
  �䲮�����㲻���书������Ǯ��(Qian bo) ��ֻ�ռ�(Meat) ������give meat to wu bo)�ɡ�
  �ҵ�������ӻ��� �鿴��ͼ��ʹ��mapָ�� ʹ��set showmap 1 ���Կ�����ǰ��ͼ
  ��ʾ:buy meat Ȼ��give meat to wu bo
  ��ɺ� ask lao about ok"NOR;       

if (me->query("nbjob",1)==10)
{
msg=HIY"�ϴ峤˵����\n��ʮһ������ 
  �ҷظ����и�ԭʼɭ�� ��ָ���������书����ȥ����һ�£����ս��Ʒ�ɡ�
  �鿴��ͼ��ʹ��mapָ�� ʹ��set showmap 1 ���Կ�����ǰ��ͼ
  �Ǳ���Σ�գ��������Σ�գ�����·�ˣ�����recall����ص������ء�
  ��ɺ� ask lao about ok"NOR;  
if (me->query("max_qi",1)< 800) me->set("max_qi",800);
if (me->query("eff_qi",1)< 800) me->set("eff_qi",800);
if (me->query("qi",1)< 800) me->set("qi",800);
if (me->query("max_neili",1)< 200) me->set("max_neili",200);
if (me->query("neili",1)< 200) me->set("neili",200);
if (me->query_skill("force",1)< 100) me->set_skill("force",100);
if (me->query_skill("dodge",1)< 100) me->set_skill("dodge",100);
if (me->query_skill("unarmed",1)< 100) me->set_skill("unarmed",100);
if (me->query_skill("parry",1)< 100) me->set_skill("parry",100);
if (me->query_skill("sword",1)< 100) me->set_skill("sword",100);
if (me->query_skill("feixian-sword",1)< 100) me->set_skill("feixian-sword",100);
if (me->query_skill("jingyiforce",1)< 100) me->set_skill("jingyiforce",100);
if (me->query_skill("softsword",1)< 100) me->set_skill("softsword",100);
}
if (me->query("nbjob",1)==11)
msg=HIY"�ϴ峤˵����\n��ʮ�������� 
  �������Եĳɹ��ɣ��Ѵ��Եõ��ĳɹ���ȥ���˻�Ǯ�ɡ�
  �鿴��ͼ��ʹ��mapָ�� ʹ��set showmap 1 ���Կ�����ǰ��ͼ
  �ҵ����� ����sell <��Ʒid>
  ��ɺ� ask lao about ok"NOR;  

if (me->query("nbjob",1)==12)
{
msg=HIY"�ϴ峤˵����\n��ʮ�������� 
  �ղŸ�����һ�����־� ������������д�֣������Ű����浽����������ȥ�ɡ�
  �鿴��ͼ��ʹ��mapָ�� ʹ��set showmap 1 ���Կ�����ǰ��ͼ
  �ҵ����� ����pawn <��Ʒid>
  ��ɺ� ask lao about ok"NOR;  
if (me->query_skill("literate",1)<=80)
{
me->set_skill("literate",80);
}

}
if (me->query("nbjob",1)==13)
msg=HIY"�ϴ峤˵����\n��ʮ�ĸ����� 
  ����������Ӧ���е�Ǯ�˰� �����Ű����浽Ǯׯ��ȥ�ɡ�
  �鿴��ͼ��ʹ��mapָ�� ʹ��set showmap 1 ���Կ�����ǰ��ͼ
  �ҵ�Ǯׯ ����deposit <Ǯid>
  ��ɺ� ask lao about ok"NOR;  

if (me->query("nbjob",1)==14)
{
msg=HIY"�ϴ峤˵����\n��ʮ������� 
  ������Ӧ���е�����ڹ��˰ɣ��ǵ�enable force <�����ڹ�>��
  ��������ˣ�������exert cureheal��exert recover�ɡ�
  ��ϸ���ݲ�ѯ help force
  ��ɺ� ask lao about ok"NOR;  
me->set("qi",me->query("max_qi",1)/2);
}
if (me->query("nbjob",1)==15)
msg=HIY"�ϴ峤˵����\n��ʮ�������� 
  �����У����ѻ����������Ҫ��
  ��������chat <����> ��˵һ�仰������:chat �������� ���λ����Ҷ�������
  �˹��ܿ��Ժ����ߵ�������Ի�����Ѱ�����
  ��ɺ� ask lao about ok"NOR;  

if (me->query("nbjob",1)==16)
msg=HIY"�ϴ峤˵����\n��ʮ�߸����� 
  �����У�ָ���ǿ��Լ򻯵ġ�
  ��������alias k kill $*����kill <id>��Ϊk <id>
  alias Ҳ���Բ�ѯ ���趨�˶��ټ������
  С��ʾ: ������ǰ���书������ʽ�ĵ�ָ������ ͬ�������趨
  ��ѯ�书�������verify|chkskill <�书id>
        �� (alias vv verify $*)
  ��ɺ� ask lao about ok"NOR;  

if (me->query("nbjob",1)==17)
msg=HIY"�ϴ峤˵����\n��ʮ�˸����� 
  �����У���������˵���ֱ����Ǻ���Ҫ�ġ�
  ��������look newbie beg Ȼ��xiuxi newbie beg
  ��ɺ� ask lao about ok
  С��ʾ:�� i ���Կ��Լ����ϵ���Ʒid ���Բ�ѯ�Լ����ϵ��� Ʒ��� 
  ͬ��xiuxi newbie beg Ҳ���Ա�� xiuxi beg
  ��ɺ� ask lao about ok"NOR;  
  
if (me->query("nbjob",1)==18)
{
msg=HIY"�ϴ峤˵����\n��ʮ�Ÿ����� 
  �����У�����װ����������˵����Ҫ ������һ���������������֮��
  ��������bangding 1 newbie armor Ȼ��bweapon 1
  ��������bangding 2 newbie sword Ȼ��bweapon 2
  �������help dazao,help bangding,help bweapon
  ����wield,unwield,wear,removeָ��ɡ�
  ��ɺ� ask lao about ok
  С��ʾ: �������ǲ�ס �������趨 alias ������ ����  �Ժ�鿴Ŷ.
  ��ɺ� ask lao about ok"NOR;  
if (!present("newbie armor",me))
{
                  ob1=new("/p/item/newbie");
                  ob1->move(me); 
}

if (!present("newbie sword",me))
{
                  ob1=new("/p/item/newbiesword");
                  ob1->move(me); 
}

}

if (me->query("nbjob",1)==19)
msg=HIY"�ϴ峤˵����\n���һ������ ����
�ϴ峤˵��������������ľ�Ҫ���˾�Ҫ������.�̶̵�ʱ����,
��ѧ�����ٶ�����.����������������ѧ���Ķ������������ڽ�
���ﴴ��һ����������˵���ء��ټ��ˣ�ask lao about ����)"NOR;  


message("vision", msg+"\n", me);  
  return me->query("name")+"���ȥ�������°ɡ�";
}             


string ask_liwu16()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili,exp,pot;
  object ob1;
  object weapon;
weapon = me->query_temp("weapon");
if (!me->query("nbjob") && me->query_temp("nbjob1",1)>=2)
{
exp=1888;
addnl(me,"exp",exp);
me->set("nbjob",1);	
return "�������������Ŭ�� ask lao about job";
}	

if (me->query("nbjob",1)==1 && me->query_temp("nbjob2",1)>=3)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",2);	
return "�������������Ŭ�� ask lao about job";
}	

if (me->query("nbjob",1)==2 && me->query_temp("nbjob3",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",3);	
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==3 && me->query_temp("nbjob4",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",4);	
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==4 && me->query_temp("nbjob5",1)==1)
{
exp=1888;
addnl(me,"exp",exp);
me->set("nbjob",5);		
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==5 && me->query_skill("sword",1)>9 && me->query_skill("feixian-sword",1)>9 
&& (string) me->query_skill_mapped("sword") == "feixian-sword")
{
exp=1888;

                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
addnl(me,"exp",exp);	
me->set("nbjob",6);	
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==6 && weapon)
{
if ((string)weapon->query("skill_type") == "sword")
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",7);	
return "�������������Ŭ�� ask lao about job";
}
}

if (me->query("nbjob",1)==7 &&  me->query_temp("nbjob8",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",8);	
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==8 && me->query_temp("nbjob9",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",9);	
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
return "�������������Ŭ�� ask lao about job";
//return "���������������Ѿ����Գ�ȥ���������ˣ� ask lao about ����";
}

if (me->query("nbjob",1)==9 && me->query_temp("nbjob10",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",10);	
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==10 && me->query_temp("isdalinb",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",11);	
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==11 && me->query_temp("isdangpu",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",12);	
                  ob1=new("/d/welcome/npc/lbook1");
                  ob1->move(me); 
return "������������һ�����־��������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==12 && me->query_temp("isdangpu2",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",13);
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 	
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==13 && me->query_temp("isbank",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",14);
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==14 && me->query_temp("ishealnb",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",15);
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==15 && me->query_temp("ischatnb",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",16);
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==16 && me->query_temp("isaliasnb",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",17);
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==17 && me->query_temp("isnbbg",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",18);
return "�������������Ŭ�� ask lao about job";
}

if (me->query("nbjob",1)==18 && me->query_temp("isnbwp",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",19);
return "�������������Ŭ�� ask lao about job";
}

  return "���������пն࿴��������Ϣ��(help) �鿴���������� ask lao about job";
}