#include <ansi.h>
inherit NPC;
int ask_force2();
int ask_force(string arg);
int ask_me();
int ask_nk();
int ask_zs1();
int ask_zs2();
int ask_zs3();
int ask_zs4();
int ask_zs5();
int ask_zs6();
int ask_hy();
int ask_hy2();
string ask_clear();
string ask_buchang();
string ask_panshi();
string ask_job();
#include "/clone/guard/party.h"
//int ask_gift();
int ask_bing();
int ask_yahuan();
int ask_yahuan2();
mapping pnames=([
"hxsd" : "hxsd",
"lds" : "lds",
"shazi": "shazi",
"lting" : "lting",
"yunlongzi" : "yunlongzi",
"hadis" : "hadisc",
"lxudd" : "lxudd",
"violet" : "violet",
"mist" : "mist",
"spray" : "spray",
"zmkk" : "zmkk",
"yoshare" : "yoshare",
"killman" : "killman",
"sos" : "sos",
"hensen" : "hensen",
"hongyue" : "hongyue",
"whym" : "whym",
"mudw": "mudw",
"green" : "green",
"yellow" : "yellow",
"baixinga" : "baixinga",
"luger" : "luger",
"lyj" : "lyj",
"liandan" : "liandan",
"ccy" : "ccy",
"helpmax" : "helpmax",
"what" : "what",
"paima" : "paima",								
"bhs" : "bhs",	
"savignyy" : "savignyy",	
"dust" : "dust",	
"qzz" : "qzz",	
"jqorzr" : "jqorzr",	
"qazqaz" : "qazqaz",	
"bsx" : "bsx",	
"parry" : "parry",	
"telnet" : "telnet",	
"ajax" : "ajax",	
"bbt" : "bbt",										
"bkl" : "bkl",										
"bry" : "bry",										
"bmr" : "bmr",										
"xianodf" : "xianodf",										
"xianoda" : "xianoda",										
"xianodab" : "xianodab",										
"xianodaa" : "xianodaa",										
"xianodaf" : "xianodaf",										
"wzliu" : "wzliu",																		
"dlc" : "dlc",																		
"game" : "game",																		
"ddbb" : "ddbb",																		
"npc" : "npc",																		
"rains" : "rains",																						
"langaoo" : "langaoo",																						
"lulusee" : "lulusee",																						
"rui" : "rui",																						
"aka" : "aka",																						
"phoenix" : "phoenix",																						
"qier" : "qier",																						
"numen" : "numen",																												
"angel" : "angel",																												
"pepsi" : "pepsi",																												
"zyy" : "zyy",																												
"ranran" : "ranran",																												
"xtm" : "xtm",																												
"kkk" : "kkk",																												
]);

string *jm1=({
"��δ��ʼ",
"ҹ̽�̼ұ� ������ˮ��",
"��ɽС��ͤ ��սԬ����",
"���������� �������Ż�",
"�Ǿ����˷� սʤ���ũ",
"���������� ս�ܶ���",
"ս���۵�ʤ �ñ�������",
});

string *jm2=({
"��δ��ʼ",
"�ػ������� �����ǿ��",
"������ʷ� �ȳ�������",
"�ⴳ������ ���������",
"�ܴ��ڸ��� ���������",
});
string *jm3=({
"��δ��ʼ",	
"�������ɽ �����ǽ���",
"���ֺڼ��� �ȳ�������", 
"���仨��ˮ ��Ѫ����ɮ",
"����Ůˮ�� ɱѪ����ɮ",
"����ܵ��� �����Ǳ���",
});
string *jm4=({
"��δ��ʼ",	
"��̽����ɽ ��ɽ��Ѱ��",
"���Ĵ���� ��ս�ȶ���",
"���������� ��ս������",
"����̽Ľ�� ���Ľ�ݸ�",
"ʶ������� ��ؤ�����",
"����ң��� ��ܶ�����",
"����ɽͯ�� ����ʮ����",
"̽���Ļʹ� սʤ����ˮ",
"�¶������� ��˫����ս",
"����ɹ��� �ܵн��Ƿ�",
});
string *jm5=({
"��δ��ʼ",	
"������ľ�� ���÷����",
"�Ա������� ����ͽ�",
"Ѱ��ɳ�߶� ʤ�һ���ͽ",
"�����л��� ս��ŷ����",
"�һ���̽�� Ӯ��������",
"½��ׯ�Ƶ� ��ܽ����",
"����ͽ��ս ��һ�ƴ�ʦ",
"����ɽ̽�� ����������",
"������Σ�� �����״��",
"�ڻ�ɽ�۽� ����ѧ���",
});
string *jm6=({
"��δ��ʼ",	
"ɱͷ�ǻ�ʤ ��ս����ʤ",
"��ս�´ﺣ ����������",
"���߲��Թ� �ܽ��ϻ���",
"��߲��Թ� ����������",
"ʶ����ҿ� ��ܼ�����",
});

string *jm7=({
"��δ��ʼ",	
"Ӫ��ìʮ�� �پȰ�����",
"����ػ��� ��ׯ������",
"��ɱ���ݻ� ����˫����",
"����̽���� ʶ�Ƽٻʺ�", 
"���������� ��ܺ����",
"��������� ��ɱ������",
"�����ر߽� ����������",
"����ʮ���� ����屦��",
});
string *jm8=({
"��δ��ʼ",	
"��������� ��������",
"�ø����ھ� �پ���ƽ֮",
"����ﲮ�� �Ǿ�С����",
"����˼���� Լ��������",
"Ѱ��ҩ���� �ܽ�������", 
"�ܵ���׷ɱ ����������",
"���ܷ�÷ׯ �Ǿ�������",
"������Ⱥ�� �ȳ���ӯӯ",
"ҹ̽��ľ�� ɱ��������",
"��ɽ����� ����������",
"��������� �ܿ�����а",
});
string *jm9=({
"��δ��ʼ",	
"��ͤ����� ����̩���",
"Ӳ������ׯ �ưٻ���ȭ",
"���Ȼ���ͩ ����կ�ᱦ",
"��ɱ������ ����������",
"���ݾȻʵ� ��ܳ¼���",
});

string *jm10=({
"��δ��ʼ",	
"��ȫ����� ȫ��ܻ���",
"�����Ī�� ����½��˫",
"�����ִ�� ������ʤ��",
"�������� �ȳ���ǧ��",
"���������� ɱ����־��",
"�������� �������ؽ�",
"�Ǵ�����̶ ̽����ȵ�",
"�ȳ�С���� ɱ���ַ���",
});
string *jm11=({
"��δ��ʼ",	
"Ѱ�������� �������̾�",
"ս�ض��İ� �ȴ�����",
"�ȳ�ʯ���� ��ܱ���ʯ",
"Ӳ�������� ��ܰ�����",
"���ͷ����� ����ڵ���",
});
string *jm12=({
"��δ��ʼ",	
"���𵺽��� �̳����޼�",
"�ػ��䵱�� ��������", 
"��������� ��������",
"�����̽��� ����������",
"̽������ׯ �ú�����ҩ",
"�������ߵ� �ܲ�˹��ʹ",
"̽������ ����ڤ����",
"�������ɮ ɱ����С��",
});
string *jm13=({
"��δ��ʼ",	
"���ɱ����� ������ѩ��",
"�γ����߽� ɱ�о�����",
"�嶾��̽�� ��ܺ�����",
"���������� ���Ԭ��־",
"��ܻ�̫�� ŭɱ�ܻ���",
});

string *jm14=({
"��δ��ʼ",	
"��ս�ڷ�կ �¾����л�",
"���ϳ����� �ɽ����Ƶ�",
"ɱ������ ���˹�̽��",
"���ؽ����� ����ĸ���",
"�ǵú�Կ�� ��սԬ����",
});


void create()
{
       set_name("������ʿ", ({ "noname", "man" }));
        set("title",HIW"һ����ʦ"NOR);
	set("long", 
              "������������ʿ��û����֪������������\n"
              "��������ռ����飬�����������(book)��(shi).\n"
              );
        set("age", 57);
        set("class", "beggar");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 700);
	set("int", 60);
	set("con", 60);
	set("dex", 700);
	set("per", 60);
	set("kar", 60);
	set("no_kill",1);
	    set("qi",   99999999);
	    set("jing", 99999999);
	set("eff_qi",   99999999);
	set("eff_jing", 99999999);
	set("max_qi",   99999999);
	set("max_jing", 99999999);
	set("neili", 554500);
	set("max_neili", 554500);
	set("jiali", 0);
	set("combat_exp", 285000000);
	set("score", 50000);                
        set_skill("strike",1200);
        set_skill("unarmed",1200);
        set_skill("dodge",1200);
        set_skill("force", 1200);
        set_skill("unarmed", 1200);
        set_skill("sword", 1200);
	set_skill("parry", 1210);
	set_skill("literate", 1200);
	set_skill("canzhi-duanhun",1300);
	set_skill("ai-sword",1300);
        map_skill("unarmed", "canzhi-duanhun");
        map_skill("parry", "canzhi-duanhun");
        map_skill("sword", "ai-sword");


set("inquiry", ([
            "book": "���鹲����ʮ�������������help tasks����йط���֪ʶ��",
            "shi": "ֻ�п�"HIR"��"+HIC+"��"+HIY+"��"+HIM+"��"+HIG+"ʯ"NOR+CYN"�����ҵ����飬��ʯ��ʮ��һ�飡",
	     "mengzhu": (: ask_me :),
//	     "��ս": (: ask_nk :),
//	     "nokill": (: ask_nk :),
	     "һת": (: ask_zs1 :),
	     "��ת": (: ask_zs2 :),
	     "��ת": (: ask_zs6 :),
	     "zhuanshen1": (: ask_zs1 :),
	     "zhuanshen2": (: ask_zs2 :),
	     "zhuanshen3": (: ask_zs6 :),
	     "ת����": (: ask_zs3 :),
	     "finalskill": (: ask_zs3 :),
	     
	     "maxexp": (: ask_zs4 :),
	     "�ɳ�": (: ask_zs4 :), 
	     "˫�ڹ�": (: ask_force2 :),
	     "force": (: ask_force2 :),
		"���": (: ask_yahuan :),
		"��������": (: ask_yahuan2 :),
		"newguard": (: ask_yahuan2 :),
		"guard": (: ask_yahuan :),
//��Ҫ������ͷ����ֻ�ܿ���һ����������ʱ������!!�����ǹط�����!!
	     "��������":(: ask_clear :),
	     "yaogift":(: ask_clear :),
//           "gift":(: ask_buchang :),
//	     "��������":(: ask_buchang :),
//	     "����":(: ask_buchang :),
//��Ҫ������ͷ����ֻ�ܿ���һ����������ʱ������!!�����ǹط�����!!
//	     "huiyuan":(: ask_hy :),
//		"��Ա": (: ask_hy :),
//	     "oldplayer":(: ask_hy2 :),
//		"�����": (: ask_hy2 :),
            ]) );
            
set_temp("apply/intelligence", 200);
set_temp("apply/strength",200);
set_temp("apply/dexerity",200);
set_temp("apply/constitution",200);
set_temp("apply/karey", 200);
set_temp("apply/percao", 200);	
set_temp("apply/armor", 5000);
set_temp("apply/defense", 200);
set_temp("apply/attack", 200);
set_temp("apply/damage", 5000);  
            
       	setup();
     carry_object("/clone/weapon/changjian")->wield();
          carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	add_action("do_answer", "answer");
	add_action("ask_force", "yaoforce");
}

int ask_hy()
{
    string week, month, year, day, time,hydata;
    string check;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
 	object me = this_player();
sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);

    if ( me->query("zhuanshen") && !me->query("ishy"))
{
command("say ��û�л�ԱȨ�ޣ����Ѿ�ת����!");
        return 1;
}

//    write("������:");
    //write(year);
    //write(month);
    //write(day);
hydata=year+month+day;
//write(hydata);

    if ( me->query("hydata")==hydata)
{
command("say ������Ѿ������Ա������!");
        return 1;
}



//neili=280+random(888);
exp=88000+random(18888);
//pot=18000+random(88888);
pot=exp/2;
neili=50;
mpgx=2;
me->add("max_neili",neili);
me->add("combat_exp",exp);
me->add("potential",pot);
me->add("mpgx",2);

//     ob = new(__DIR__"red");
//     ob->move(me);
     me->set("hydata",hydata);
message_vision("$n��������ǿ��!��������"+exp+"��Ǳ������"+pot+"�㡣��������"+neili+"�㡣���ɹ�������2�㡣\n" , this_object(), me );
     //return "��ã�\n"+me->query("name")+"��"+HIR"������ǿ�����"NOR+"������"+neili+",����"+exp+",Ǳ��"+pot+",���ɹ��׶��㡣\n";
	return 1;
}


int ask_hy2()
{
    string week, month, year, day, time,hydata,arg;
    string check;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
 	object ob;
 	object me = this_player();
sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
arg=me->query("id");

   if ( me->query("combat_exp")<=50000)
{
command("say ���������书������,��ľ���̫��! ��Ҫ������!");
        return 1;
}

if (!stringp(pnames[arg])) 
{
command("say ��û�еǼ�!");
        return 1;
}
    if ( me->query("isoldp")==1)
{
command("say ������Ѿ��������������!");
        return 1;
}


     ob = new("/clone/gift/newbiegift");
     ob->move(me);
     me->set("isoldp",1);
log_file("ishy", sprintf("%s ����������嵵�� ON %s.\n", me->query("id"),ctime(time())));
message_vision("$n�õ���������嵵תվ��������¼����־ϵͳ��.�緢�ֶ���,ֱ�����е�.\n" , this_object(), me );
command("say лл������Ժ����֧��!");
     //return "��ã�\n"+me->query("name")+"��"+HIR"������ǿ�����"NOR+"������"+neili+",����"+exp+",Ǳ��"+pot+",���ɹ��׶��㡣\n";
	return 1;
}


int accept_object(object me, object ob)
{
object shi; 
if( ob->query("money_id") && ob->value() >= 2000)
{	
	 if (!present("xdshi", me))
	{
	shi = new("/clone/misc/findbook");
	command("say �ð�,"+me->query("name")+"��Ȼ����Ǯ���Ҿ͸���һ�飡\n");
	shi->move(me);
	message_vision("$N��һ��"HIR"��"+HIC+"��"+HIY+"��"+HIM+"��"+HIG+"ʯ"NOR"������$n��\n" , this_object(), me );
	} else 
	command("say �㲻������һ�������Ҫ��Ǯ��û�գ�\n");
return 1;
}

command("say лл�����Ҳ�Ҫ�ⶫ����");
return 0;
}
int ask_me()
{
	string info,name,id,file,infoa,infob;
	object me,ob;
	me=this_player();
	ob=me;
	info = read_file("/data/npc/champion.o");


if ((int)ob->query("jinyong/book1",1)!= sizeof(jm1)-1
|| (int)ob->query("jinyong/book2",1)!= sizeof(jm2)-1
|| (int)ob->query("jinyong/book3",1)!= sizeof(jm3)-1
|| (int)ob->query("jinyong/book4",1)!= sizeof(jm4)-1
|| (int)ob->query("jinyong/book5",1)!= sizeof(jm5)-1
|| (int)ob->query("jinyong/book6",1)!= sizeof(jm6)-1
|| (int)ob->query("jinyong/book7",1)!= sizeof(jm7)-1
|| (int)ob->query("jinyong/book8",1)!= sizeof(jm8)-1
|| (int)ob->query("jinyong/book9",1)!= sizeof(jm9)-1
|| (int)ob->query("jinyong/book10",1)!= sizeof(jm10)-1
|| (int)ob->query("jinyong/book11",1)!= sizeof(jm11)-1
|| (int)ob->query("jinyong/book12",1)!= sizeof(jm12)-1
|| (int)ob->query("jinyong/book13",1)!= sizeof(jm13)-1
|| (int)ob->query("jinyong/book14",1)!= sizeof(jm14)-1
) 
{
command("say ��û��������߽���(questlists) ���ʸ���ս!");
        return 1;
}

if (ob->query("jinyong/all",1)==2)
{
command("say ���Ѿ��������ս!");
        return 1;
}

	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
{
if (id==this_player()->query("id")) {this_player()->move("/d/biwu/b11");return 1;} 

}	
	
info = read_file("/data/npc/champion1.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
{
if (id==this_player()->query("id")) {this_player()->move("/d/biwu/a11");return 1;}
}
if (!ob->query("jinyong/all")) ob->set("jinyong/all",1);	
tell_object(this_player(),"������ʿ˵���� �ðɣ�����Σ�����أ�ǧ�������������������Σ�ա��Լ�С�İɣ�\n");
this_player()->move("/d/biwu/hole");

return 1;
}

int ask_nk()
{
if(this_player()->query("PKS",1)> 10 
||this_player()->query_condition("killer")
//||this_player()->query("guard/flag")
||this_player()->query("age") < 18
 )
{
tell_object(this_player(),"������ʿ˵������û���ʸ񣬲���������սϵͳ��\n");
}
else {
tell_object(this_player(),"������ʿ˵���� �ðɣ�����������սϵͳ��\n");
this_player()->set_temp("nokill",1);
}
return 1;
}





void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "������ʿЦ��˵���������û���ã�\n");
	command("hehe");
}

void die()
{
	unconcious();
}

int ask_yahuan2()
{
 	object me = this_player();

	if (!me->query("guard/flag"))
		command("say ƾ�����ڵ���������û���ʸ�����Ҫ����أ�");
	if (!me->query("guard/active"))
		command("say �����ڻ�û�����!");
	else {
		command("nod " + me->query("id"));
		command("say ���Ѿ����¿��Ի�һ����Ů�ˣ�");
		command("say ����ȥʮ��֮һ�ľ���");
	me->delete("guard/active");
  me->add("combat_exp",-(int)me->query("combat_exp")/10);
	}
	return 1;
}


int ask_yahuan()
{
 	object me = this_player();

	if (!me->query("guard/flag"))
		command("say ƾ�����ڵ���������û���ʸ�����Ҫ����أ�");
	else if (me->query("guard/active"))
		command("say �㲻���Ѿ��������ô��");
	else {
		command("nod " + me->query("id"));
		if (me->query("gender") == "����") {
			command("say ������������һЩ��Ů�����Ƕ������ŵ��ӣ���
\t\t�䵱��\t\t(wudang)
\t\t��ɽ��\t\t(huashan)
\t\t���չ�\t\t(lingjiu)
\t\t�һ���\t\t(taohua)
\t\t��ػ�\t\t(tiandihui)
\t\t����\t\t(mingjiao)
\t\t��Ĺ��\t\t(gumu)
\t\tؤ��\t\t(gaibang)
\t\tȫ���\t\t(quanzhen)
\t\t����\t\t(dali)
\t\t���ư�\t\t(tiezhang)
\t\tĽ������\t(murong)
\t\t������\t\t(kunlun)
\t\t������\t\t(lingxiao)
\t\t�嶾��\t\t(wdjiao)
\t\t����ɽ\t\t(baituo)
\t\t������\t\t(emei)
\t\t��ң��\t\t(xiaoyao)
\t\tѩɽ��\t\t(mizong)
\t\t������\t\t(xingxiu)
\t\t������\t\t(feitian)
\t\t������\t\t(shenlong)
\t\t����\t\t(tangmen)
\t\t���½�\t\t(riyue)
\t\t����\t\t(shaolin)
����Ҫ����һ�������Ѿ��������answer�ش��ң�");
		} else {
			command("say ������������һЩ���ӣ����Ƕ������ŵ��ӣ���
\t\t�䵱��\t\t(wudang)
\t\t��ɽ��\t\t(huashan)
\t\t���չ�\t\t(lingjiu)
\t\t�һ���\t\t(taohua)
\t\t��ػ�\t\t(tiandihui)
\t\t����\t\t(mingjiao)
\t\t��Ĺ��\t\t(gumu)
\t\tؤ��\t\t(gaibang)
\t\tȫ���\t\t(quanzhen)
\t\t����\t\t(dali)
\t\t���ư�\t\t(tiezhang)
\t\tĽ������\t(murong)
\t\t������\t\t(kunlun)
\t\t������\t\t(lingxiao)
\t\t�嶾��\t\t(wdjiao)
\t\t����ɽ\t\t(baituo)
\t\t������\t\t(emei)
\t\t��ң��\t\t(xiaoyao)
\t\tѩɽ��\t\t(mizong)
\t\t������\t\t(xingxiu)
\t\t������\t\t(feitian)
\t\t������\t\t(shenlong)
\t\t����\t\t(tangmen)
\t\t���½�\t\t(riyue)
\t\t����\t\t(shaolin)
����Ҫ����һ���������ͯ������answer�ش��ң�");
		}
		me->set_temp("guard/answer", 1);
	}
	return 1;
}
int do_answer(string arg)
{
	object me = this_player(), ob;
	int i, flag = 0;
	
	if (!me->query_temp("guard/answer"))
		return 0;
		
	// Ҫ����������Ҫһ�����������ƣ�
	for (i = 0; i < sizeof(ps); i++)
		if (arg == ps[i]["party"]) {
			flag = 1;
			break;
		}
	if (!flag) {
		command("kick " + me->query("id"));
		command("say ����Ҫ������ҿ�û�У�");
		return 1;
	}
	command("ok");
	me->delete_temp("guard/answer");

	me->delete("guard/status");
	me->delete("guard/skills");
	me->delete("guard/gender");
	me->delete("guard/learned");
	me->delete("guard/skill_map");
	me->delete("guard/skill_prepare");
	me->set("guard/flag", 1);
	me->set("guard/active", 1);
	if (me->query("gender") == "����")
		me->set("guard/gender", "girl");
	else
		me->set("guard/gender", "boy");
	me->set("guard/status", ps[i]["status"]);
	me->set("guard/skills", ps[i]["skills"]);
	me->set("guard/learned", ps[i]["learned"]);
	me->set("guard/skill_map", ps[i]["skill_map"]);
	me->set("guard/skill_prepare", ps[i]["skill_prepare"]);
	me->save();
	
	command("say �ӽ��������͸������ˣ������ʹ��(zhaohuan)�������ٻ�����");
		
	return 1;
}

/*string ask_panshi()
{

        mapping quest,item,npc;
        object me=this_player();
if (me->query("npanshi"))
return HIR"����λ"+RANK_D->query_respect(me)+"���Ѿ�Ϊ�������ʦ��¼�ˡ�"NOR;
command("say ����ϵͳ�������Ͱ���һ�ΰ�");
me->set("betrayer",0);
me->set("npanshi",1);
return HIW"����λ"+RANK_D->query_respect(me)+"�Ժ�Ҫ�ú����ˡ�"NOR;
}
*/

string ask_buchang()
{
        mapping quest,item,npc;
        object ob;
        object me=this_player();
if ((int)me->query("combat_exp") < 5000)
return HIR"����λ"+RANK_D->query_respect(me)+"�����ְɡ�"NOR;
  if(me->query("liwuopen/1")>0)
return HIR"����λ"+RANK_D->query_respect(me)+"�Ѿ����ù��˰ɡ�"NOR;
  if(me->query("liwuopen/2")>0)
return HIR"����λ"+RANK_D->query_respect(me)+"�Ѿ����ù��˰ɡ�"NOR;

 me->set("liwuopen/2",1);
 ob=new("/clone/gift/biggift");
        ob->set_amount(1);
        ob->move(me);
return HIR"����λ"+RANK_D->query_respect(me)+"���տ��֡�ף���彡��!!"NOR;
}
string ask_clear()
{
        mapping quest,item,npc;
        object ob;
        object me=this_player();

 me->delete("liwuopen");

return HIW"����λ"+RANK_D->query_respect(me)+"���Ѿ�������ˡ�"NOR;
}


int ask_zs1()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

     if(obj->is_busy())
        return notify_fail("��������æ��û��ɱ�ˡ�\n");

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

    if ( obj->query("zhuanshen"))
{
command("say ���Ѿ�ת������!");
        return notify_fail("�����Ѿ�ת������!\n");
}
    if (!obj->query("migong/lev3")
    ||!obj->query("migong/lev2")
    ||!obj->query("migong/lev1")
    ||!obj->query("migong/lev4")
    ||!obj->query("migong/lev5")
    ||!obj->query("migong/lev8")
    ||!obj->query("migong/lev6")
    ||!obj->query("migong/lev7")
    ||!obj->query("migong/lev9")
    ||!obj->query("migong/lev10")

    )
{
command("say ��û���ʸ�ת��!����������Թ����񵽵�10��!");
        return notify_fail("����û���ʸ�ת��\n");
}
    if ( (int)obj->query("combat_exp",1) < 12000000)
{
command("say ��û���ʸ�ת��!1ת��Ҫ12M���顣");
        return notify_fail("����û���ʸ�ת��!1ת��Ҫ12M���顣\n");
}
    if ( (int)obj->query("max_neili",1) < 5000)
{
command("say ��û���ʸ�ת��!�����������!!");
        return notify_fail("����û���ʸ�ת��!\n");
}

    if ( (int)obj->query("mpgx",1) < 50)
{
command("say ��û���ʸ�ת��!������ɹ��ײ���!!");
        return notify_fail("����û���ʸ�ת��!\n");
}	
		
		
    obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili"));
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
if (mapp(skill_status = obj->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = obj->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->delete_skill(sname[i]);//ɾ���Լ����й���
}
		obj->map_skill("unarmed");
		obj->map_skill("hammer");
		obj->map_skill("blade");
		obj->map_skill("stick");
		obj->map_skill("staff");
		obj->map_skill("club");
		obj->map_skill("throwing");
		obj->map_skill("parry");
		obj->map_skill("dodge");
		obj->map_skill("magic");
		obj->map_skill("spells");
		obj->map_skill("leg");
		obj->map_skill("axe");
		obj->map_skill("array");
		obj->map_skill("whip");	
		obj->map_skill("finger");
		obj->map_skill("hand");	
		obj->map_skill("cuff");	
		obj->map_skill("claw");	
		obj->map_skill("strike");	

		obj->prepare_skill("unarmed");
		obj->prepare_skill("hammer");
		obj->prepare_skill("blade");
		obj->prepare_skill("stick");
		obj->prepare_skill("staff");
		obj->prepare_skill("club");
		obj->prepare_skill("throwing");
		obj->prepare_skill("parry");
		obj->prepare_skill("dodge");
		obj->prepare_skill("magic");
		obj->prepare_skill("spells");
		obj->prepare_skill("leg");
		obj->prepare_skill("axe");
		obj->prepare_skill("array");
		obj->prepare_skill("whip");	
		obj->prepare_skill("finger");
		obj->prepare_skill("hand");	
		obj->prepare_skill("cuff");	
		obj->prepare_skill("claw");	
		obj->prepare_skill("strike");	
                obj->reset_action();

// 1
        if ( obj->query("per",1) < 60)
obj->set("per",obj->query("per")+20);

//2
        if ( obj->query("str",1) < 60)
obj->set("str",obj->query("str")+20);

//3
        if ( obj->query("dex",1) < 60)
 obj->set("dex",obj->query("dex")+20);

//4
        if ( obj->query("int",1) < 60)
 obj->set("int",obj->query("int")+20);

//5
        if ( obj->query("con",1) <60)
 obj->set("con",obj->query("con")+20);


//6
        if ( obj->query("kar",1) <60)
 obj->set("kar",obj->query("kar")+20);

        obj->set("betrayer",0);
        obj->set("title","��ͨ����");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
        obj->delete("family");
        obj->delete("party");
obj->delete("blade_get");
obj->delete("work/wakuang");
obj->delete("work/wunon");
obj->delete("work/penlen");
obj->delete("work/zhujian");
obj->delete("work/zhudao");
obj->delete("work/zhubanzi");
obj->delete("work/buyu");
obj->delete("work/dalie");
obj->delete("work/zhaojiu");
obj->delete("work/zhujia");
obj->delete("work");
obj->delete("breakup");
obj->delete("last_getzhen");
obj->delete("dali/fail");
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
obj->set("combat_exp",0);  
obj->set("mpgx",0);  
obj->set("learned_points",0);
obj->set("potential",obj->query("learned_points"));
                obj->set("mpgx",0);

        //obj->delete("levels");
        obj->save();
obj->set("tforceok",2);
obj->set("guard/flag",1);
obj->set("zhuanshen",1);
obj->delete("jinyong");
obj->delete("blade_get");
obj->delete("szj/failed");
obj->delete("jiuyin/shang-failed");
obj->delete("jiuyin/xia-failed");
obj->delete("zhou/fail");
obj->delete("zhou/jieyi");
obj->delete("jiuyin/gumu-failed");
obj->delete("zhou/failed");
obj->delete("obstacle");
if (obj->query("hyvip"))
{
if (obj->query("hyvip")) obj->add("hymoney",30);
if (obj->query("hyvip")) obj->set("combat_exp",500000);
if (obj->query("hyvip")) obj->add("potential",300000);
}
//obj->set("nbjob",0);
//obj->set("nbtjob32",0);
//obj->set("nbtjob33",0);
    write(HIR"һת�ɹ�,�����µ�½!\n"NOR);
tell_object(obj,HIR"һת�ɹ�,�����µ�½!\n"NOR);
	log_file("static/ZS",
		sprintf("%s һת��ʱ��: %s\n", geteuid(obj), ctime(time())) );

        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + obj->name(1) +
                              "һת�ˡ�");
    "/cmds/usr/quit"->main(obj);

    return 1;
}

int ask_zs2()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

     if(obj->is_busy())
        return notify_fail("��������æ��û��ɱ�ˡ�\n");

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

    if ( !obj->query("zhuanshen"))
{
command("say ��û����һת!");
        return notify_fail("����û����һת!\n");
}

    if (obj->query("zhuanbest")  )
{
command("say ���Ѿ���ת����! ");
        return notify_fail("���Ѿ���ת����!\n");
}


    if (!obj->query("migong/lev11")
    ||!obj->query("migong/lev12")
    ||!obj->query("migong/lev13")
    ||!obj->query("migong/lev14")
    ||!obj->query("migong/lev15")
    )
{
command("say ��û���ʸ�ת��!����������Թ����񵽵�15��!");
        return notify_fail("����û���ʸ�ת��\n");
}
    if ( (int)obj->query("combat_exp") < 100000000)
{
command("say ��û���ʸ�ת��!2ת��Ҫ100M���顣");
        return notify_fail("����û���ʸ�ת��,2ת��Ҫ100M����!\n");
}
    if ( (int)obj->query("max_neili") < 6000)
{                   
command("say ��û���ʸ�ת��!�����������!!");
        return notify_fail("����û���ʸ�ת��!\n");
}
    if ( (int)obj->query("mpgx",1) < 100)
{
command("say ��û���ʸ�ת��!������ɹ��ײ���!!");
        return notify_fail("����û���ʸ�ת��!\n");
}	











    obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili"));
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
if (mapp(skill_status = obj->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = obj->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->delete_skill(sname[i]);//ɾ���Լ����й���
}
		obj->map_skill("unarmed");
		obj->map_skill("hammer");
		obj->map_skill("blade");
		obj->map_skill("stick");
		obj->map_skill("staff");
		obj->map_skill("club");
		obj->map_skill("throwing");
		obj->map_skill("parry");
		obj->map_skill("dodge");
		obj->map_skill("magic");
		obj->map_skill("spells");
		obj->map_skill("leg");
		obj->map_skill("axe");
		obj->map_skill("array");
		obj->map_skill("whip");	
		obj->map_skill("finger");
		obj->map_skill("hand");	
		obj->map_skill("cuff");	
		obj->map_skill("claw");	
		obj->map_skill("strike");	

		obj->prepare_skill("unarmed");
		obj->prepare_skill("hammer");
		obj->prepare_skill("blade");
		obj->prepare_skill("stick");
		obj->prepare_skill("staff");
		obj->prepare_skill("club");
		obj->prepare_skill("throwing");
		obj->prepare_skill("parry");
		obj->prepare_skill("dodge");
		obj->prepare_skill("magic");
		obj->prepare_skill("spells");
		obj->prepare_skill("leg");
		obj->prepare_skill("axe");
		obj->prepare_skill("array");
		obj->prepare_skill("whip");	
		obj->prepare_skill("finger");
		obj->prepare_skill("hand");	
		obj->prepare_skill("cuff");	
		obj->prepare_skill("claw");	
		obj->prepare_skill("strike");	
                obj->reset_action();
        if ( obj->query("per") < 100)
        {
	obj->set("per",obj->query("per")+20);
        }
        if ( obj->query("str") < 100)
        {
	obj->set("str",obj->query("str")+20);
        }
        if ( obj->query("dex")< 100)
        {
	obj->set("dex",obj->query("dex")+20);
        }
        if ( obj->query("int")< 100)
        {
	obj->set("int",obj->query("int")+20);
        }
        if ( obj->query("con")< 100)
        {
	obj->set("con",obj->query("con")+20);
        }
        if ( obj->query("kar")< 100)
        {
	obj->set("kar",obj->query("kar")+20);
        }

        obj->set("betrayer",0);
        obj->set("title","��ͨ����");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
        obj->delete("family");
        obj->delete("party");
obj->delete("work/wakuang");
obj->delete("work/wunon");
obj->delete("work/penlen");
obj->delete("work/zhujian");
obj->delete("work/zhudao");
obj->delete("work/zhubanzi");
obj->delete("work/buyu");
obj->delete("work/dalie");
obj->delete("work/zhaojiu");
obj->delete("work/zhujia");
obj->delete("work");
obj->delete("breakup");
obj->delete("last_getzhen");
obj->delete("dali/fail");
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
obj->set("zhuanbest",1);
                obj->set("combat_exp",0);
                obj->set("mpgx",0);
obj->set("learned_points",0);
obj->set("potential",obj->query("learned_points"));
obj->delete("blade_get");
obj->delete("szj/failed");
obj->delete("jiuyin/shang-failed");
obj->delete("jiuyin/xia-failed");
obj->delete("zhou/fail");
obj->delete("zhou/jieyi");
obj->delete("jiuyin/gumu-failed");
obj->delete("zhou/failed");
obj->set("guard/flag",1);
obj->set("tforceok",2);

obj->set("zhuanbest",1);
obj->delete("szj/failed");
obj->delete("zhou/failed");
obj->delete("zhou/fail");
obj->delete("zhou/jieyi");
obj->set("jiuyin/full",1);
    write(HIR"��þ���!\n"NOR);
obj->set("szj/passed",1);
    write(HIR"�������!\n"NOR);
obj->set("double_attack",1);
write(HIR"��û���!\n"NOR);
if (obj->query("hyvip"))
{
if (obj->query("hyvip")) obj->add("hymoney",30);
if (obj->query("hyvip")) obj->set("combat_exp",500000);
if (obj->query("hyvip")) obj->add("potential",300000);
}
        obj->save();
    write(HIR"��ת�ɹ�,�����µ�½!\n"NOR);
tell_object(obj,HIR"��ת�ɹ�,�����µ�½!\n"NOR);
obj->delete("jinyong");
obj->delete("obstacle");
obj->delete("last_alert");
	log_file("static/ZS",
		sprintf("%s ��ת��ʱ��: %s\n", geteuid(obj), ctime(time())) );
CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + obj->name(1) +"��ת�ˡ�");
    "/cmds/usr/quit"->main(obj);

    return 1;
}

int ask_force(string arg)
{
    int i,temp,j;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();
if (!arg)
return notify_fail("��ҪҪ��ʲô�أ�\n");
if (obj->is_busy())
{
command("say ����æ����!");
        return notify_fail("����æ����!\n");
}
    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

    if ( !obj->query("zhuanshen")
    &&!obj->query("guard/flag")
    &&!obj->query("zhuanbest")
    )
{
command("say ��û������ʹ�������ڹ�!");
        return notify_fail("��û���ʸ�ʹ�������ڹ�!\n");
}
    if ( !obj->query("tforceok"))
{
command("say ���Ѿ���������������!");
        return notify_fail("��û���ʸ�ʹ�������ڹ�!\n");
}

    if ( (int)obj->query("tforceok")==1)
{
command("say �Ҳ����Ѿ�������������������!");
        return notify_fail("��û���ʸ�ʹ�������ڹ�!\n");
}

    if ( (int)obj->query("combat_exp") < 800000)
{
command("say ������һ���书����!ֻ��һ�λ���!!");
        return notify_fail("������һ���书����!\n");
}
    if ( (int)obj->query("combat_exp") < 1000000)
{
command("say ��������һ���ڹ�������!ֻ��һ�λ���!!");
        return notify_fail("������һ���书����!\n");
}
if (mapp(skill_status = obj->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
j =0;
skill_status = obj->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
if (SKILL_D(sname[i])->exert_function_file() 
&& sname[i]!="force"
&& sname[i]!="taixuan-gong"
&& sname[i]!="jiuyin-zhengong")
{
j=j+1;
}
CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + obj->query("name") +"����" + j +"���ڹ���");
}
if (j < 1) 
{
command("say ����ѧһ���ڹ�����!����ֻ��һ��!!");
        return notify_fail("������һ���书����!\n");
}

if (j > 5) 
{
command("say ���Ѿ��������ڹ���!!����ֻ��һ��!!");
        return notify_fail("������һ���书����!\n");
}

if (arg=="wudang")
{
obj->set_skill("taiji-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );
}
else if (arg=="huashan")
{
obj->set_skill("zixia-shengong",105);
obj->set_skill("huashan-neigong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );
}
else if (arg=="lingjiu")
{
obj->set_skill("beiming-shengong",105);
obj->set_skill("bahuang-gong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="mingjiao")
{
obj->set_skill("jiuyang-shengong",105);
obj->set_skill("shenghuo-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="shaolin")
{
obj->set_skill("yijinjing",105);
obj->set_skill("hunyuan-yiqi",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="xueshan")
{
obj->set_skill("longxiang",105);
obj->set_skill("xiaowuxiang",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="xiaoyao")
{
obj->set_skill("beiming-shengong",105);
obj->set_skill("bahuang-gong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="riyue")
{
obj->set_skill("kuihua-xinfa",105);
obj->set_skill("tmdafa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}

else if (arg=="taohua")
{
obj->set_skill("bibo-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="tiandihui")
{
obj->set_skill("yunlong-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="gumu")
{
obj->set_skill("yunv-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="gaibang")
{
obj->set_skill("huntian-qigong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="quanzhen")
{
obj->set_skill("xiantian-qigong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="dali")
{
obj->set_skill("kurong-changong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="tiezhang")
{
obj->set_skill("guiyuan-tunafa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="murong")
{
obj->set_skill("shenyuan-gong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="kunlun")
{
obj->set_skill("xuantian-wuji",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="lingxiao")
{
obj->set_skill("bingxue-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="wdjiao")
{
obj->set_skill("wudu-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="emei")
{
obj->set_skill("linji-zhuang",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="xingxiu")
{
obj->set_skill("huagong-dafa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="shenlong")
{
obj->set_skill("shenlong-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="baituo")
{
obj->set_skill("hamagong",105);
obj->set("tforceok",1);

	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );
}
else if (arg=="tangmen")
{
obj->set_skill("biyun-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="feitian")
{
obj->set_skill("shayi-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else
command("say �������кܶ����ڹ����ֱ�Ϊ
\t\t�䵱��\t\t(wudang)
\t\t��ɽ��\t\t(huashan)
\t\t���չ�\t\t(lingjiu)
\t\t�һ���\t\t(taohua)
\t\t��ػ�\t\t(tiandihui)
\t\t����\t\t(mingjiao)
\t\t��Ĺ��\t\t(gumu)
\t\tؤ��\t\t(gaibang)
\t\tȫ���\t\t(quanzhen)
\t\t����\t\t(dali)
\t\t���ư�\t\t(tiezhang)
\t\tĽ������\t(murong)
\t\t������\t\t(kunlun)
\t\t������\t\t(lingxiao)
\t\t�嶾��\t\t(wdjiao)
\t\t������\t\t(shaolin)
\t\t������\t\t(emei)
\t\t������\t\t(xingxiu)
\t\t������\t\t(shenlong)
\t\t����ɽ\t\t(baituo)
\t\t����\t\t(tangmen)
\t\t����������\t(feitian)
\t\tѩɽ��\t\t(xueshan)
\t\t��ң��\t\t(xiaoyao)
\t\t�������\t(riyue)
����Ҫ��һ���ڹ�Ϊ������");
    "/cmds/usr/save"->main(obj);
if (!wizardp(obj))
obj->start_busy(8);
    return 1;
}

int ask_force2()
{
    int i,temp,j;
    object obj;

obj=this_player();

if (obj->is_busy())
{
command("say ����æ����!");
        return notify_fail("����æ����!\n");
}
    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");


command("say �������кܶ����ڹ����ֱ�Ϊ
\t\t�䵱��\t\t(wudang)
\t\t��ɽ��\t\t(huashan)
\t\t���չ�\t\t(lingjiu)
\t\t�һ���\t\t(taohua)
\t\t��ػ�\t\t(tiandihui)
\t\t����\t\t(mingjiao)
\t\t��Ĺ��\t\t(gumu)
\t\tؤ��\t\t(gaibang)
\t\tȫ���\t\t(quanzhen)
\t\t����\t\t(dali)
\t\t���ư�\t\t(tiezhang)
\t\tĽ������\t(murong)
\t\t������\t\t(kunlun)
\t\t������\t\t(lingxiao)
\t\t�嶾��\t\t(wdjiao)
\t\t������\t\t(shaolin)
\t\t������\t\t(emei)
\t\t������\t\t(xingxiu)
\t\t������\t\t(shenlong)
\t\t����ɽ\t\t(baituo)
\t\t����\t\t(tangmen)
\t\t����������\t(feitian)
\t\tѩɽ��\t\t(xueshan)
\t\t��ң��\t\t(xiaoyao)
\t\t�������\t(riyue)
����(yaoforce)Ҫ��һ���ڹ�Ϊ������");
if (!wizardp(obj))
obj->start_busy(8);
    return 1;
}

int ask_zs3()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

     if(obj->is_busy())
        return notify_fail("��������æ��û��ɱ�ˡ�\n");

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

    if (!obj->query("4zhuan")
    && !obj->query("5zhuan"))
{
command("say ��û���ʸ�Ҫ����!");
        return notify_fail("����û���ʸ�Ҫ����\n");
}
    if ( (int)obj->query("combat_exp") < 800000)
{
command("say �㾭��ߵ�����Ҫ��!");
        return notify_fail("�㾭��ߵ�����Ҫ��!\n");
}
    if ( (int)obj->query("max_neili") < 1000)
{
command("say ��û���ʸ�ת��!�����������!!");
        return notify_fail("����û���ʸ�ת��!\n");
}
if (obj->query("4zhuan",1) || obj->query("5zhuan",1))
{
obj->set_skill("tianrenheyi",205);
write(HIY"����书�����˺�һ��!\n"NOR);
}

if (obj->query("zhuanfinal/7",1)==1 && obj->query("4zhuan",1))
{
obj->set_skill("yinyang-shiertian",205);
write(HIY"����书������ʮ�����졿!\n"NOR);
}
if (obj->query("zhuanfinal/8",1)==1 && obj->query("4zhuan",1))
{
obj->set_skill("never-defeated",205);
write(HIY"����书�������񹦡�!\n"NOR);
}

    write(HIR"���ܻ�óɹ�!\n"NOR);
tell_object(obj,HIR"���ܻ�óɹ�!\n"NOR);
    return 1;
}




int ask_zs5()
{
    int i,temp,maxexp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();
obj->set_temp("xmud",1);
tell_object(obj,HIR"xmud��Ӧ�ɹ�!\n"NOR);
    return 1;

}        

int ask_zs4()
{
    int i,temp,maxexp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

     if(obj->is_busy())
        return notify_fail("��������æ���ء�\n");

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

    if (!obj->query("4zhuan")
    && !obj->query("5zhuan"))
{
command("say �㲻��ҪҪ��óɳ�����!");
        return notify_fail("���˲���ҪҪ��óɳ�����\n");
}
    if ( (int)obj->query("combat_exp") < 590000)
{
command("say �㾭��ߵ�����Ҫ��!");
        return notify_fail("�㾭��ߵ�����Ҫ��!\n");
}
    if ( (int)obj->query("max_neili") < 1000)
{
command("say ��û���ʸ�ת��!�����������!!");
        return notify_fail("����û���ʸ�ת��!\n");
}

    if ( (int)obj->query_temp("menpaijob",1) < 12)
{
command("say �㻹û������12������������!!");
        return notify_fail("�㻹û������12������������!!\n");
}

maxexp=6000000+(obj->query("expmax",1)*500000);

    if ( (maxexp-(int)obj->query("combat_exp",1)) > 800000)
{
command("say ��û�дﵽ�ɳ�ƿ����������!");
        return notify_fail("��û�дﵽ�ɳ�ƿ����������!\n");
}


if (obj->query_temp("menpaijob",1) >= 12)
{
if (obj->query("expmax",1) < 1)
{
obj->set("expmax",1);
}
else
{
obj->add("expmax",1);
}
}
obj->set_temp("menpaijob",0);
tell_object(obj,HIR"�ɳ�������óɹ�!\n"NOR);
    return 1;
}



int ask_zs6()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

     if(obj->is_busy())
        return notify_fail("��������æ��û��ɱ�ˡ�\n");

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

    if ( !obj->query("zhuanshen"))
{
command("say ��û����һת!");
        return notify_fail("����û����һת!\n");
}

    if ( !obj->query("zhuanbest"))
{
command("say ��û������ת!");
        return notify_fail("����û������ת!\n");
}
if (obj->query("4zhuan"))
{
command("say ���Ѿ�3ת���� ");
        return notify_fail("���Ѿ�3ת���ˡ�\n");
}


    if (!obj->query("migong/lev16")
    ||!obj->query("migong/lev17")
    ||!obj->query("migong/lev18")
    ||!obj->query("migong/lev19")
    ||!obj->query("migong/lev20")
    ||!obj->query("migong/lev21")
    )
{
command("say ��û���ʸ�ת��!����������Թ����񵽵�21��!");
        return notify_fail("����û���ʸ�ת��\n");
}
    if ( (int)obj->query("combat_exp") < 200000000)
{
command("say ��û���ʸ�ת��!3ת��Ҫ200M���顣");
        return notify_fail("����û���ʸ�ת��,3ת��Ҫ200M����!\n");
}
    if ( (int)obj->query("max_neili") < 6000)
{                   
command("say ��û���ʸ�ת��!�����������!!");
        return notify_fail("����û���ʸ�ת��!\n");
}

    if ( (int)obj->query("mpgx",1) < 100)
{
command("say ��û���ʸ�ת��!������ɹ��ײ���!!");
        return notify_fail("����û���ʸ�ת��!\n");
}	



if (obj->query("zhuanbest")
&& (int)obj->query("combat_exp") > 200000000 )
{
obj->delete("last_alert");
    write(HIR"3ת�ɹ�!\n"NOR);

    obj->set("4zhuan",1);


    
if (random(4)==0)
{
obj->set("zhuanfinal/6",1);
write(HIY"�����������ʿ��˫�������ɾ���!\n"NOR);
obj->set("zhuanfinal/5",1);
write(HIY"�����������Ԫ�󷨡������ɾ���!\n"NOR);
obj->set("zhuanfinal/1",1);
write(HIY"���������Ԫ�������ն�ɾ���!\n"NOR);
}
else if (random(4)==1)
{
obj->set("zhuanfinal/2",1);
write(HIY"�����������Ӱ���١������ɾ���!\n"NOR);
obj->set("zhuanfinal/6",1);
write(HIY"�����������ʿ��˫�������ɾ���!\n"NOR);
obj->set("zhuanfinal/3",1);
write(HIY"�����������ħ���������ɾ���!\n"NOR);
}
else if (random(4)==2)
{
obj->set("zhuanfinal/3",1);
write(HIY"�����������ħ���������ɾ���!\n"NOR);
obj->set("zhuanfinal/4",1);
write(HIY"������������ǲ��������ɾ���!\n"NOR);
obj->set("zhuanfinal/5",1);
write(HIY"�����������Ԫ�󷨡������ɾ���!\n"NOR);

}
else 
{
obj->set("zhuanfinal/4",1);
write(HIY"������������ǲ��������ɾ���!\n"NOR);
obj->set("zhuanfinal/1",1);
write(HIY"���������Ԫ�������ն�ɾ���!\n"NOR);
obj->set("zhuanfinal/2",1);
write(HIY"�����������Ӱ���١������ɾ���!\n"NOR);
}

obj->set("zhuanfinal/8",1);
write(HIY"����书�������񹦡�!\n"NOR);

obj->delete("jinyong");
obj->delete("obstacle");
obj->delete("last_alert");


if (obj->query("hyvip")==4)
{
obj->set("zhuanfinal/7",1);
write(HIY"����书������ʮ�����졿!\n"NOR);

}
    obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili"));
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
if (mapp(skill_status = obj->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = obj->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->delete_skill(sname[i]);//ɾ���Լ����й���
}
		obj->map_skill("unarmed");
		obj->map_skill("hammer");
		obj->map_skill("blade");
		obj->map_skill("stick");
		obj->map_skill("staff");
		obj->map_skill("club");
		obj->map_skill("throwing");
		obj->map_skill("parry");
		obj->map_skill("dodge");
		obj->map_skill("magic");
		obj->map_skill("spells");
		obj->map_skill("leg");
		obj->map_skill("axe");
		obj->map_skill("array");
		obj->map_skill("whip");	
		obj->map_skill("finger");
		obj->map_skill("hand");	
		obj->map_skill("cuff");	
		obj->map_skill("claw");	
		obj->map_skill("strike");	

		obj->prepare_skill("unarmed");
		obj->prepare_skill("hammer");
		obj->prepare_skill("blade");
		obj->prepare_skill("stick");
		obj->prepare_skill("staff");
		obj->prepare_skill("club");
		obj->prepare_skill("throwing");
		obj->prepare_skill("parry");
		obj->prepare_skill("dodge");
		obj->prepare_skill("magic");
		obj->prepare_skill("spells");
		obj->prepare_skill("leg");
		obj->prepare_skill("axe");
		obj->prepare_skill("array");
		obj->prepare_skill("whip");	
		obj->prepare_skill("finger");
		obj->prepare_skill("hand");	
		obj->prepare_skill("cuff");	
		obj->prepare_skill("claw");	
		obj->prepare_skill("strike");	
                obj->reset_action();
        if ( obj->query("per") < 120)
        {
	obj->set("per",obj->query("per")+20);
        }
        if ( obj->query("str") < 120)
        {
	obj->set("str",obj->query("str")+20);
        }
        if ( obj->query("dex")< 120)
        {
	obj->set("dex",obj->query("dex")+20);
        }
        if ( obj->query("int")< 120)
        {
	obj->set("int",obj->query("int")+20);
        }
        if ( obj->query("con")< 120)
        {
	obj->set("con",obj->query("con")+20);
        }
        if ( obj->query("kar")< 120)
        {
	obj->set("kar",obj->query("kar")+20);
        }

        obj->set("betrayer",0);
        obj->set("title","��ͨ����");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
        obj->delete("family");
        obj->delete("party");
obj->delete("work/wakuang");
obj->delete("work/wunon");
obj->delete("work/penlen");
obj->delete("work/zhujian");
obj->delete("work/zhudao");
obj->delete("work/zhubanzi");
obj->delete("work/buyu");
obj->delete("work/dalie");
obj->delete("work/zhaojiu");
obj->delete("work/zhujia");
obj->delete("work");
obj->delete("breakup");
obj->delete("last_getzhen");
obj->delete("dali/fail");
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
                obj->set("combat_exp",0);
                obj->set("mpgx",0);
obj->set("learned_points",0);
obj->set("potential",obj->query("learned_points"));
obj->delete("blade_get");
obj->delete("szj/failed");
obj->delete("jiuyin/shang-failed");
obj->delete("jiuyin/xia-failed");
obj->delete("zhou/fail");
obj->delete("zhou/jieyi");
obj->delete("jiuyin/gumu-failed");
obj->delete("zhou/failed");
obj->set("guard/flag",1);
obj->set("tforceok",2);
if (obj->query("hyvip"))
{
if (obj->query("hyvip")) obj->add("hymoney",30);
if (obj->query("hyvip")) obj->set("combat_exp",500000);
if (obj->query("hyvip")) obj->add("potential",300000);
}
        obj->save();
    write(HIR"��ת�ɹ�,�����µ�½!\n"NOR);
tell_object(obj,HIR"��ת�ɹ�,�����µ�½!\n"NOR);
if (obj->query("zhuanbest"))
{
	obj->delete("jinyong");
	log_file("static/ZS",
		sprintf("%s ��ת��ʱ��: %s\n", geteuid(obj), ctime(time())) );
CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + obj->name(1) +"��ת�ˡ�");
}

    "/cmds/usr/quit"->main(obj);

    return 1;
}

}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        
        damage = 3000 + random(3000);
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
if (me->is_busy()) me->start_busy(1);
me->clear_condition();

        return HIB "$N" HIB "���١���һ��ʹ��������������ʱ��$n"
               HIB "ʧȥ���ң������������Ż��С�\n" NOR;

}

