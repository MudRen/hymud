// moye.c  Īа
// Written by Doing Lu  1998/11/2
//������� ���, ����1,����2,����3,����,ID
inherit NPC;
//inherit F_NOCLONE;

#include <ansi.h>
inherit __DIR__"user_weapond.c";
int	ask_me();
//int	ask_me2();
int	no_money();

string *typeshi2=({
RED"��Ѫʯ"NOR,
HIC"����ʯ"NOR,
MAG"ܽ��ʯ"NOR,
WHT"��ɽʯ"NOR,
GRN"����ʯ"NOR,
HIG"�⾧ʯ"NOR,
HIM"��ȸʯ"NOR,
HIB"����ʯ"NOR,
HIY"���ʯ"NOR,
});

string *typeshi1=({
HIY"��"NOR,
CYN"ľ"NOR,
GRN"ˮ"NOR,
RED"��"NOR,
YEL"��"NOR,
HIM"��"NOR,
HIW"��"NOR,
HIB"��"NOR,
WHT"��"NOR,
BBLK"��"NOR,
HIC"��"NOR,
HIR"ħ"NOR,
HIC"����"NOR,
CYN"����"NOR,
YEL"��Դ"NOR,
RED"����"NOR,
GRN"��Ԩ"NOR,
HIG"����"NOR,
WHT"��ʯ"NOR,
MAG"��ʯ"NOR,
HIC"����"NOR,
HIW"����"NOR,
HIR"����"NOR,
YEL"����"NOR,
HIY"����"NOR,
HIG"����"NOR,
GRN"����"NOR,
BLU"����"NOR,
});

void create()
{
	set_name("Īа", ({ "mo ye", "moye", "mo" }));
	set("long", "����������������һ����ʳ�˼��̻��ģ����������������ʦ�ɽ������ӡ�\n" );

	set("nickname", HIY "����" NOR);
	set("gender", "Ů��");
	set("attitude", "friendly");
  set("qi",100000);
  set("jing",100000);
  set("max_qi",100000);
  set("max_jing",100000);
  
  set("neili",100000);
  set("max_neili",100000);

	set("combat_exp",9000000);
	set("age", 25);
	set("per", 30);
	set("shen_type", 0);
	set_skill("sword",1000);
set_skill("ai-sword",1000);
map_skill("sword", "ai-sword");
	set("str", 2000);			// ��֤������Ϊ���ɹ�������ܲ��˶���

	set("inquiry", ([
		"dazao" : (: ask_me :),
		"����׼��" : (: ask_me :),
		"ûǮ" : (: no_money :),
		"ԭ��" : "���Ƶ��߿ɲ���û��ԭ�ϰ���Ҫ�����ƺ������͵���"
                         "����ʯһ��Ķ�����\n          Ҫ�����ƺ÷��߾�"
                         "�������˿��Щ��������Щԭ�Ϻ����ң����������󰡣�\n",
		"�۸�" : "������Ҫһǧ���ƽ𶨽�",
		"����" : "�������(setname)��ָ������Ʒ�����ơ�",	
		"��ɫ" : "�������(setcolor)��ָ������Ʒ�����ơ�",	
	]));

        setup();

        set("startroom", "/d/item/jianchang");
  //      check_clone();
        if (! this_object()) return;

carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object me;

	// ���ѯ�ʱ�־
        if (! objectp(me = this_player()) || ! interactive(me))
                return;

	add_action("do_show", "show");
  add_action("do_answer", "answer");
  add_action("do_answer2", "setnumber");
  add_action("do_answer3", "setname");
  add_action("do_answer4", "setcolor");
	if (me->query_temp("item/status") == "item_gived")
	{
		remove_call_out("greeting2");
		call_out("greeting2", 1, me);
	} else
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}

void greeting(object me)
{
	if (objectp(me) && environment(me) == environment())
	{
		message_vision("$NЦ�Ŷ�$n˵����ã�������������"
                               "��\n", this_object(), me);
	}
}

void greeting2(object me)
{
	if (objectp(me) && environment(me) == environment())
	{
		message_vision("$N��$n˵����Ǯ�Ϳ��Դ�����Ŷ��\n",
                               this_object(), me);
	}
}

int do_show(string arg)
{
	object	me;
	object	ob,ob1;
	string	msg;
        string  mat;
	int	power_point;
	int	value;
	int	n;
mapping type;


	string type2;
	string type1;
	string name;
	me = this_player();
	if (! arg)
                return notify_fail("�����ʲô����Ҫ������ô��\n");

        mat = arg;
	power_point = 0;

	if (! objectp(ob = present(mat, me)))
		return notify_fail("���˰ɣ�������û�� " + mat + " ���ֶ�����\n");



if ( ob->query("upyushi"))
{

	if ( me->query_temp("item/upyushi"))
		return notify_fail("���Ѿ����˸������"+me->query_temp("item/upyushin")+"��\n");

	if (! me->query_temp("paid/moye2"))
		return notify_fail("���˰ɣ����ȸ�����ɡ�\n");


if (ob->query("upyushilb")) me->set_temp("item/upyushilb",ob->query("upyushilb"));
if (ob->query("upyushilv")) me->set_temp("item/upyushilv",ob->query("upyushilv"));
if (ob->query("upyushi")) me->set_temp("item/upyushi",ob->query("id"));
if (ob->query("upyushi")) me->set_temp("item/upyushin",ob->query("name"));

type2=typeshi2[ob->query("upyushilb")];
type1=typeshi1[ob->query("upyushilv")];
name=type1+"֮"+type2;

	message_vision("$N��$n˵����" 
		"����Ҫ����Ĳ�����" + name + "�ɣ�\n",
 this_object(), this_player());
me->set_temp("paid/moye2",0);
me->delete_temp("paid/moye2");
destruct(ob);
return 1;	
	
}		


	if (! ob->query("material_attrib"))
	{
		message_vision("$Nһ㶣���$n˵�������ֶ���Ҳ��������"
                               "�ƣ���û��˵����\n", this_object(), me);
		return notify_fail("����������ɡ�\n");

	}
 if (!me->query_temp("nwtemp") && !me->query_temp("natemp"))
                {
                        message_vision("$Nҡҡͷ����$n˵����˵��Ҫ��ʲô������\n",
                                       this_object(), me);
		return notify_fail("����������ɡ�\n");

                }


 if (me->query_temp("nwtemp") )
                {
if ( !ob->query("kuangshi") && !ob->query("wyushi"))
{
                        message_vision("$Nҡҡͷ����$n˵����������Ҫ��ʯ���飬����������ټ���һ�飡\n",
                                       this_object(), me);
		return notify_fail("����������ɡ�\n");
}
if ( ob->query("kuangshi"))
{
if ( !objectp(ob1 = present(mat+" 2", me)))
{
                        message_vision("$Nҡҡͷ����$n˵����������Ҫ��ͬ��ʯ���飬һ�鲻����\n",
                                       this_object(), me);
		return notify_fail("����������ɡ�\n");
}
}

}

if (me->query_temp("natemp") )
                {
if ( !ob->query("kuangshi") && !ob->query("ayushi")  && !ob->query("buliao"))
{
                        message_vision("$Nҡҡͷ����$n˵����������Ҫ��ʯһ�飬����һ�飬����������ټ���һ�飡\n",
                                       this_object(), me);
		return notify_fail("����������ɡ�\n");
}
                }

if (ob->query("kuangshi")) me->set_temp("item/kuangshi",ob->query("material"));
if (ob->query("buliao")) me->set_temp("item/buliao",ob->query("material"));
if (ob->query("ayushi")) me->set_temp("item/ayushi",ob->query("id"));
if (ob->query("wyushi")) me->set_temp("item/wyushi",ob->query("id"));	

if (me->query_temp("nwtemp")) type=TYPE1[me->query_temp("nwtemp")-1];
if (me->query_temp("natemp")) type=TYPE2[me->query_temp("natemp")-1];

        msg = sprintf("$N��ϸ���˿�$n�ó���ԭ�ϣ�˵��������ԭ�ϴ�����ߣ�\n" +
	              "�ǿ��Դ�����ߵģ�Ҫ��û����"
                      "���������ɷ����ɡ�\n", chinese_number(value));
	message_vision(msg, this_object(), me);
	message_vision("$N��$n˵����" 
		"����Ҫ����" + type["TYPE3"] + "�ɣ�\n"
		"�����ڵ�׼���������:\n"
		"�����ÿ�ʯ��"+MDESC_WEAPON[me->query_temp("item/kuangshi")]+"\n"
		"�����ò���: "+MDESC_ARMOR[me->query_temp("item/buliao")]+"\n"
		"��������ʯ:"+MDESC_WYU[me->query_temp("item/wyushi")]+"\n"
    "��������ʯ:"+MDESC_AYU[me->query_temp("item/ayushi")]+"\n",
 this_object(), this_player());
if (ob)
destruct(ob);
if (ob1)
destruct(ob1);
	return 1;
}

// ������ʾ��Ϣ
int ask_me()
{
	message_vision("$N��$n˵����" 
		"����Ҫ�����Լ��ĵ�����\n"
		"�����������Ϊ�������������ͷ��ߣ����ǵ�һ���ġ�\n"
		"���Ⱦ������������(answer)��Ȼ��������λ��(setnumber)��\n"
		"Ȼ���ԭ�ϸ���(show) ԭ��������Ҫ ����ԭ�� ����еĻ���û���һ����ʯ��\n"
    "������Ҫ һ��ԭ�� һ�鲼�� ����еĻ���û���һ����ʯ��\n"
		"�����������ȸ�һǧ���ƽ�Ķ���"
    "���Ǿ�һ�ֽ�Ǯ��һ�ֽ�����\n", this_object(), this_player());
	return 1;
}

int no_money()
{
        object me;
        object ob;

        me = this_player();
	message_vision("$N�۾�һ�ɣ���$n˵����ûǮ����ûǮ����ɶ�£�"
                       "���ֲ��ǲ���ү��\n", this_object(), me);
	return 1;
}

// ���ܶ���
int accept_object(object me, object ob)
{
        string status;
	int    val,val2;

        status = query_temp("item/status");


                if (! ob->query("money_id"))
                {
                        command("say �㻹�ǿ�㽻Ǯ�ɣ�Ҫ��ûǮ����˵��");
                        return 0;
                }



// �����ֵ
		val = 1000;
		val2 = 1500;
		message_vision("$N��$n˵�����ܺã�����������Ҫ" +
                               chinese_number(val) + "���ƽ𣬽�Ǯ�ɡ�\n",
			       this_object(), me);

		message_vision("$N��$n˵�����ܺã�����������Ҫ" +
                               chinese_number(val2) + "���ƽ𣬽�Ǯ�ɡ�\n",
			       this_object(), me);

                val *= 10000;
                val2 *= 10000;
		if (wizardp(me))
		{
			message_vision("$N��ϸ���˿�$n��Ц��˵����ԭ"
                                       "������ʦ����ô����������ˡ�\n",
                                       this_object(), me);
			val = 1;
			val2 = 2;
		}
		if ( me->query("nbjob")==33 || me->query("nbjob")==34   )
		{
			if( me->query("nmoneydz",1) <=5)
			{
			message_vision("$N��ϸ���˿�$n��Ц��˵����ԭ"
                                       "����������ѧϰ����ô��������ͺ��ˡ�\n",
                                       this_object(), me);
			val = 1;
		}
		me->add("nmoneydz",1);
		}
        if (ob->query("money_id"))
	{
                object origin;
                mixed p;
                string *types;

/* if (!me->query_temp("nwtemp") && !me->query_temp("natemp"))
                {
                        message_vision("$Nҡҡͷ����$n˵����˵��Ҫ��ʲô������\n",
                                       this_object(), me);
			return 0;
                }
*/
        if (ob->value() < val)
        {
                command("say Ǯ��������");
                return 0;
        }
if  (ob->value() < val2)
{   
		message_vision("$N��$n˵�����ã���͸�������������"
                               "��ʲô�������������(answer ����)��\n"
		"�������Դ��� ��(SWORD) ��(BLADE) ��(HAMMER) ��(WHIP) ��(CLUB) \n"
		"�������ܴ��� ��(STAFF)  ����(THROWING)  ذ��(DAGGER) ��(AXE)\n"
		"���߿��Դ��� ����(HANDS) ��װ(CLOTH) ����(ARMOR) ѥ��(BOOTS) ͷ��(HEAD)��\n"
		"���߻��ܴ��� ����(NECK)�Ǵ�(SURCOAT)����(SHIELD) ����(WAIST) ����(WRISTS)��\n",
                               this_object(), me);

                me->set_temp("paid/moye", 1);
}
else
{
		message_vision("$N��$n˵��������͸������װ��,����(show) һ������������Ĳ���,\n"
		"Ȼ���Ҹɽ��������װ����(duanlian) \n",
                               this_object(), me);
                me->set_temp("paid/moye2", 1);

}		
                return -1;
        }

	message_vision("Īа�۾�һ�ɣ���$N˵�����������Щ������ʲô���Ҳ�Ҫ��\n", me);
	return 0;
}

int do_answer(string arg)
{
        object money;
        object ob;
        object me;
        object ganjiang;
mapping type;
        me = this_player();
//        if (me->query_temp("item/status") != "answer_type")
//                return 0;
	
        if (! arg)
                return notify_fail("��Ҫ�ش�ʲô��\n");

        if (! me->query_temp("paid/moye", 1))
        {

                command("say ��...�Һͷ��ҲҪ�������"
                        "˵һǧ���ƽ���ô����");
                return 1;
        }


me->delete_temp("nwtemp");
me->delete_temp("natemp");
//write(arg);
	switch(arg){
case "SWORD":	me->set_temp("nwtemp",1); break;
case "BLADE":	me->set_temp("nwtemp",2); break;
case "HAMMER":	me->set_temp("nwtemp",3); break;
case "WHIP":	me->set_temp("nwtemp",4); break;
case "CLUB":	me->set_temp("nwtemp",5); break;
case "STAFF":	me->set_temp("nwtemp",6); break;
case "THROWING":	me->set_temp("nwtemp",7); break;
case "DAGGER":	me->set_temp("nwtemp",8); break;
case "AXE":	me->set_temp("nwtemp",9); break;
	}
if (me->query_temp("nwtemp")) type=TYPE1[me->query_temp("nwtemp")-1];
	switch(arg){
case "HANDS":	me->set_temp("natemp",1); break;
case "CLOTH":	me->set_temp("natemp",2); break;
case "ARMOR":	me->set_temp("natemp",3); break;
case "BOOTS":	me->set_temp("natemp",4); break;
case "HEAD":	me->set_temp("natemp",5); break;
case "NECK":	me->set_temp("natemp",6); break;
case "SURCOAT":	me->set_temp("natemp",7); break;
case "SHIELD":	me->set_temp("natemp",8); break;
case "WAIST":	me->set_temp("natemp",9); break;
case "WRISTS":	me->set_temp("natemp",10); break;
	}

if (me->query_temp("natemp")) type=TYPE2[me->query_temp("natemp")-1];

         if (!me->query_temp("nwtemp") && !me->query_temp("natemp"))
{
	message_vision("$N��$n˵����\n" 
		"�������Դ��� ��(SWORD) ��(BLADE) ��(HAMMER) ��(WHIP) ��(CLUB) \n"
		"�������ܴ��� ��(STAFF)  ����(THROWING)  ذ��(DAGGER) ��(AXE)\n"
		"���߿��Դ��� ����(HANDS) ��װ(CLOTH) ����(ARMOR) ѥ��(BOOTS) ͷ��(HEAD)��\n"
		"���߻��ܴ��� ����(NECK)�Ǵ�(SURCOAT)����(SHIELD) ����(WAIST) ����(WRISTS)��\n"
    "��úÿ�һ�°ɣ�\n", this_object(), this_player());

                return notify_fail("�Ǻǣ�����û�취�������ණ����ע��һ�����Ҫ��д��\n");
}
me->delete_temp("paid/moye");
        message_vision("$N��$n����֪����,����Ҫ����" + type["TYPE3"] + "�ɣ�\n",
                       this_object(), me);



	return 1;
}


int do_answer2(string arg)
{
        object money;
        object ob;
        object me;
        object ganjiang;
mapping type;
int i;
    string cmd, temp;
    int args, ratio, round;
        me = this_player();
//        if (me->query_temp("item/status") != "answer_type")
//                return 0;
	
        if (! arg)
                return notify_fail("��Ҫ�趨�������Ϊ�ڼ���������������5��(1-5)�����߿�����10��(1-10)��\n");

 if (!me->query_temp("nwtemp") && !me->query_temp("natemp"))
                {
                        message_vision("$Nҡҡͷ����$n˵����˵��Ҫ��ʲô������\n",
                                       this_object(), me);
		return notify_fail("����������ɡ�\n");

                }

 	if(!arg || (sscanf(arg, "%d", i)!=1 ))
		return notify_fail("��Ҫ�趨�������Ϊ�ڼ���������������5��(1-5)�����߿�����10��(1-10)��\n");
		
// write(i+"");
 
 if (me->query_temp("nwtemp") && ( i >5 || i <1) )
                {
   message_vision("$Nҡҡͷ����$n˵����˵��Ҫ��ʲô������������5��(1-5) \n",
                                       this_object(), me);
		return notify_fail("����������ɡ�\n");

                }

 if (me->query_temp("natemp") && ( i > 10 || i <1) )
                {
   message_vision("$Nҡҡͷ����$n˵����˵��Ҫ��ʲô�����߿�����10��(1-10) \n",
                                       this_object(), me);
		return notify_fail("����������ɡ�\n");

                }
me->set_temp("item/dzwz",i);
        message_vision("$N��$n����֪����,����Ҫ�����" + i + "��λ�ðɣ�\n",
                       this_object(), me);



	return 1;
}


int do_answer3(string arg)
{
        object money;
        object ob;
        object me;
        object ganjiang;
mapping type;
int i;
    string cmd, temp;
    int args, ratio, round;
        me = this_player();
//        if (me->query_temp("item/status") != "answer_type")
//                return 0;
	

 if (!me->query_temp("nwtemp") && !me->query_temp("natemp"))
                {
                        message_vision("$Nҡҡͷ����$n˵����˵��Ҫ��ʲô������\n",
                                       this_object(), me);
		return notify_fail("����������ɡ�\n");

                }
        if (! arg)
                return notify_fail("��Ҫ�趨������߽�ʲô����?\n");


 	if(!arg )
		return notify_fail("��Ҫ�趨�������Ϊʲô����?\n");
		
// write(i+"");
 
me->set_temp("item/itname",arg);
        message_vision("$N��$n����֪����,����Ҫ����Ķ�����:" + arg + " �ɣ�\n",
                       this_object(), me);



	return 1;
}





int do_answer4(string arg)
{
        object money;
        object ob;
        object me;
        object ganjiang;
mapping type;
int i;
    string cmd, temp;
    int args, ratio, round;
        me = this_player();
//        if (me->query_temp("item/status") != "answer_type")
//                return 0;
	
        if (! arg)
                return notify_fail("��Ҫ�趨�������Ϊʲôɫ? ��1-13��ѡ��\n ""HIY"",""HIG"",""RED"",""MAG"",""YEL"",""HIC"",""HIW"",""HIR"",""HIB"",""CYN"",""WHT"",""HIM"",""BLU"" \n");

 if (!me->query_temp("nwtemp") && !me->query_temp("natemp"))
                {
                        message_vision("$Nҡҡͷ����$n˵����˵��Ҫ��ʲô������\n",
                                       this_object(), me);
		return notify_fail("����������ɡ�\n");

                }

 	if(!arg || (sscanf(arg, "%d", i)!=1 ))
		return notify_fail("��Ҫ�趨�������Ϊ������ɫ?\n");
		
// write(i+"");
 
 if ( i >13 || i <1 )
                {
   message_vision("$Nҡҡͷ����$n˵����Ҫ�趨�������Ϊʲôɫ? ��1-13��ѡ��\n ""HIY"",""HIG"",""RED"",""MAG"",""YEL"",""HIC"",""HIW"",""HIR"",""HIB"",""CYN"",""WHT"",""HIM"",""BLU"" \n\n",
                                       this_object(), me);
		return notify_fail("����������ɡ�\n");

                }

me->set_temp("item/color",i);
        message_vision("$N��$n����֪����,����Ҫ�����" + me->query_temp("item/color") + "����ɫ�ɣ�\n",
                       this_object(), me);



	return 1;
}
