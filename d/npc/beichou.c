// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
int ask_pk();
inherit NPC;
int ask_hy();
int ask_hygoods();
string ask_liwu15();
string ask_liwu16();
#include "/quest/givegift.c"
private string chinese_types(string types)
{
        switch(types)
        {
        case "object"             :    return HIC "��Ʒ" NOR;
        case "objamount"          :    return HIC "��Ʒ" NOR;
        case "special"            :    return HIG "���⼼��" NOR;
        case "special2"           :    return HIW "ת������" NOR;
        case "story"              :    return HIM "����" NOR;
        case "package"            :    return HIR "��" NOR;
        case "card"               :    return HIY "��" NOR;
        case "gold"               :    return HIY "��" NOR;
        default                   :    return HIR "δ֪" NOR;
        }
}

mapping goods = ([
        "double"  :          "˫������:1:double:card:���ε�½,˫������",
        "monthcard"  :          "�¶Ȼ�Ա:30:monthcard:card:��Ա�¿� �ͳ�����Ա�ʸ�",
        "seasoncard"            : "���Ȼ�Ա:60:seasoncard:card:��Ա���� ���м���Ա�ʸ� ",
        "yearcard"              : "��Ȼ�Ա:200:yearcard:card:��Ա�꿨 ��10���������� �߼���Ա�ʸ�",
        "forevercard"           : "�����Ա:500:forevercard:card:�����Ա �ͳ�Ѩͭ�� �ǻһ�Ա�ʸ�",
   "strdan"  : "������:5:/clone/buy/strdan:object:������������ĵ�ҩ ��ߵ�30",
        "intdan"  : "���Ե�:5:/clone/buy/intdan:object:�����������Եĵ�ҩ ��ߵ�30(ת���50)",
        "condan"  : "���ǵ�:5:/clone/buy/condan:object:����������ǵĵ�ҩ ��ߵ�30(ת���50)",		
        "dexdan"  : "����:5:/clone/buy/dexdan:object:�����������ĵ�ҩ ��ߵ�30(ת���50)",
        "kardan"  : "��ò��:10:/clone/buy/kardan:object:�������츣Դ����ò�ĵ�ҩ ��ߵ�30(ת���50)",	
        "force2"  : "˫�ڵ�:20:/clone/buy/force2:object:��������ѡ��˫�ڹ�",	
        "zqdan"  : "������:2:/clone/buy/zqdan:object:�������� һ����ʮ��",	
        "hcdan"  : "�ش���:5:/clone/buy/hcdan:object:�ı����䵽ʮ����",	
        "zndan"  : "׳�굤:5:/clone/buy/zndan:object:�ı����䵽��ʮ��",		
        "xqdan"  : "а����:2:/clone/buy/xqdan:object:����а�� һ����ʮ��",			
        "htdan"  : "��Ϳ��:5:/clone/buy/htdan:object:������������ ��͵�10",				
        "wldan"  : "������:5:/clone/buy/wldan:object:����������� ��͵�10",					
        "neilidan"  : "������:1:/clone/buy/neilidan:object:������������200��",
        "ygdan"  : "�������:10:/clone/buy/ygdan:object:��һ�ж� �������ϲ���״̬,��ʦ��־",					        	        		
        "newbie"  : "���ְ�:30:/clone/buy/newbie:object:����һ�����ƽ�10�������� 10���Ź�",	
        "czdan2"  : "�ɳ�����:5:/clone/buy/czdan2:object:��ת��ת��ң���óɳ�����6��",	
        "czdan3"  : "�ɳ���:20:/clone/buy/czdan:object:��ת��ת��ң���óɳ�����50��",	
        "newbiezs"  : "������·��:5:/clone/buy/newbiezs:object:ʮ���� ����Ǳ�� ��ʮ���������� �˵��Ź�",					
        "psdan"  : "ƽ��:5:/clone/buy/psdan:object:�ı�ʦ�ţ���ұ�Ϊƽ�� ����ʦ��¼",		
        "wgwan"  : "�书��:5:/clone/buy/wgdan:object:ֱ������ĳ���书100�� ���֧�ֵ�600�� ",			
        "learn1"  : "ѧϰѫ��:50:/clone/buy/learn-emblem:object:ѧϰ�ٶȼӱ�",					        	        	
        "study1"  : "��ȡѫ��:50:/clone/buy/study-emblem:object:ѧϰ������",				
        "tishenwawa"  : "��������:1:/clone/buy/tishenwawa:object:�������޿���Ϊ�㵵��һ��",
        "tongren"  : "��Ѩͭ��:50:/clone/buy/tongren:object:��Ѩͭ�˳�Ѩʱ����������",
        "dushi"  : "�쾦�����:100:/clone/buy/dushi:object:�쾦����� ��һ�ж� �ɷ���ʹ��",
        "migongfu"  : "�Թ�Ѱ·:5:/clone/buy/migongfu:object:�Թ�Ѱ·",
        "yangwan"  : "������:10:/clone/box/new2/24:object:��Ϊ����",
        "yinwan"  : "������:10:/clone/box/new2/23:object:��ΪŮ��",

]);



string get_types(string arg)
{
        string strtmp;
        mixed * items;

        strtmp = goods[arg];
        items = explode(strtmp, ":");

        return items[3];
}
int sort_object(string str1, string str2)
{
        if( get_types(str1) == "package" ) return 1;
        if( get_types(str2) == "package" ) return -1;

        if( get_types(str1) == "objamount" ) return 1;
        if( get_types(str2) == "objamount" ) return -1;

        if( get_types(str1) == "object" ) return 1;
        if( get_types(str2) == "object" ) return -1;

        if( get_types(str1) == "story" ) return 1;
        if( get_types(str2) == "story" ) return -1;

        if( get_types(str1) == "special" ) return 1;
        if( get_types(str2) == "special" ) return -1;

        if( get_types(str1) == "special2" ) return 1;
        if( get_types(str2) == "special2" ) return -1;
        
        if( get_types(str1) == "card" ) return 1;
        if( get_types(str2) == "card" ) return -1;

        if( get_types(str1) == "gold" ) return 1;
        if( get_types(str2) == "gold" ) return -1;

        return -1;
}

public varargs void show_goods(string arg)
{
        string strtmp;
        int i, j;
        mixed * obs, all, items;

        obs = keys(goods);

        all = unique_array(obs, (:  get_types($1) == "objamount" ? 1 : get_types($1) == "object" ? 2 :
                                    get_types($1) == "story" ? 3 : get_types($1) == "special" ? 4 :
                                    get_types($1) == "special2" ? 5 : get_types($1) == "card" ? 6 : 
                                    get_types($1) == "package" ? 7 : 8 :));

        all = sort_array(all, (: sort_object($1[0], $2[0]) :));

        write(HIY "��Ա�̵�Ŀǰ�������»��\n" NOR);
        write(sprintf(HIW "%-16s%-16s%-10s%-10s%s\n" NOR,
                      "����", "����", "�۸�($HY)", "����", "��Ҫ˵��"));
        write(HIG "-------------------------------------------------------------------------------\n\n" NOR);

        for (i = 0; i < sizeof(all); i ++)
        {
                strtmp = "";
                items = ({});

                for(j = 0; j < sizeof(all[i]); j ++)
                {
                        strtmp = goods[all[i][j]];
                        items = explode(strtmp, ":");
                        if (sizeof(items) != 5)
                        {
                                write("strtmp made items != 5 is : " + strtmp + "\n");
                                return;
                        }
                        write(sprintf(HIW "%-16s%-16s" HIY "%-10s" HIW "%-26s%-50s\n" NOR,
                                      items[0], all[i][j], items[1], chinese_types(items[3]), items[4]));
                }
        }

        write(HIG "����ָ��" HIY ":" HIG "buygoods ����\n" NOR);
        write(HIG "�����������" HIY "��" HIG "��ǵķ����Ϊ�����Ա���ޡ�\n" NOR);
        write(HIG "�������Ķ��й�˵��������ǰ�뿼������� ���޲��ˡ���˻���\n" NOR);
        write(HIG "-------------------------------------------------------------------------------\n\n" NOR);
}

void create()
{
        set_name("����", ({ "bei chou", "bei", "chou", "beichou" }));
        set("long", @LONG
����һ������Ϸ�Ӵ�����С��ͷ�����ü���
����������һ�����ࡣ˭����֪����ǵ�����
���кųơ����ͱ���Ϸ�ӱ�������������
����֮�£���ȴҲ��������ƽ��η��֮�ˡ�
LONG);
        set("nickname", HIW "��Ϸ��" NOR);
        set("title", HIC "����̩��" NOR);
        set("gender", "����" );
        set("age", 68);
        set("attitude", "friendly");
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
	set("combat_exp", 85000000);
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
                "�¶Ȼ�Ա"  :"����(buygoods)�¶Ȼ�Ա��,�ͻ�Ա����,������Ա�ʸ� ÿ����ȡ��Ա������\n",
                "���Ȼ�Ա"  :"����(buygoods)���Ȼ�Ա��,�ͻ�Ա����,�м���Ա�ʸ� ����ȡ��Ա����(���ּ�2��)��\n",
                "��Ȼ�Ա"  :"����(buygoods)��Ȼ�Ա��,�ͻ�Ա����,�߼���Ա�ʸ� ��10���������� ����ȡ��Ա����(���ּ�3��)��\n",
                "�����Ա"  :"����(buygoods)�����Ա��,�ͻ�Ա����,�ǻһ�Ա�ʸ� ��10���������� ��Ѩͭ�� ����ȡ��Ա����(���ּ�4��)��\n",
                "��ս": (: ask_pk :),
                "challenge": (: ask_pk :),	
                "��Ա��": (: ask_hygoods :),
                "membergoods": (: ask_hygoods :),
                "membercards": (: ask_hygoods :),	
        	      "membergift":(: ask_hy :),
            		"��Ա����": (: ask_hy :),
            			"����" : (: ask_liwu15 :),
"job" : (: ask_liwu15 :),
"ok" : (: ask_liwu16 :),
"����" : (: ask_liwu16 :),
        ]) );

        set("chat_chance", 1);
        set("chat_msg",({
                CYN "���������е�˵��������㲻�����㣬��������ô��Ϸ���Ҷ�֪����\n" NOR,
        }));

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
	add_action("buy_goods", "buygoods");
}


int ask_hygoods()
{
    string week, month, year, day, time,hydata;
    string check;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
 	object me = this_player();
show_goods();
        return 1;
}



public int buy_goods(string which)
{
        mixed * all, items;
        mixed specials;
        string strtmp;
        int i, vip, value, money;
        object buy_ob;
object ob=this_player();



        all = keys(goods);
        if (member_array(which, all) == -1)
        {
                write("�Բ���û����Ҫ�������Ʒ " + HIR + which + NOR + "�� ����һ��"
                      "�Ұ�(ask bei chou about ��Ա��) ��\n" NOR);
                return 1;

        }

        strtmp = goods[which];
        items = explode(strtmp, ":");
        sscanf(items[1], "%d", value);

        if (items[2] == "manual")
        {
                write("�Բ��𣬸÷�������� admin �ֶ�ʵ�֣��뼰ʱ�� admin ��ϵ��\n");
                return 1;
        }

        vip   = ob->query("hyvip");
        money = ob->query("hymoney");

        // ��Ա�ۿ�
        // ��Ա�ۿ�
if (items[3]=="object")
{
        if (vip == 4)
                value = value * 80 / 100;
        else
        if (vip == 3)
                value = value * 85 / 100;
        else
        if (vip == 2)
                value = value * 90 / 100;
}


        if (value < 1) value = 1;
        if (!value) value = 1;

        
        
        if (value < 1) value = 1;
        if ((int)ob->query("hymoney") < 1)
        {
                write("�Բ������ĺ���������������\n");
                return 1;
        }

        if (money < value)
        {
                write("�Բ������ĺ���������������\n");
                return 1;
        }

        switch(items[3])
        {
        case "package":


                switch( which )
                {
                case "newbie" :
                        //MEMBER_D->db_fee_member(ob, 31);
                        break;


                case "yj-rune" :
                        for (i = 0; i < 7; i++)
                        {
                        }
                        break;
                default :
                        break;
                }

                write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                return 1;

        case "object":

                buy_ob = new(items[2]);
                if (! objectp(buy_ob))
                {
                        write("������Ʒʧ�ܣ����뱾վADMIN��ϵ��\n");
                        return 0;
                }


                buy_ob->move(ob, 1);
                ob->add("hymoney",-value);
                write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                return 1;

        case "objamount":
                buy_ob = new(items[2]);
                if (! objectp(buy_ob))
                {
                        write("������Ʒʧ�ܣ����뱾վADMIN��ϵ��\n");
                        return 0;
                }

                if (which == "putizi")
                        buy_ob->set_amount(20);
                else
                if (which == "jiuzhuan")
                        buy_ob->set_amount(10);
                else
                if (which == "yuqingsan")
                        buy_ob->set_amount(120);
                else
                if (which == "tianxiang")
                        buy_ob->set_amount(15);
                else
                if (which == "xuanhuang1")
                        buy_ob->set_amount(5);

                buy_ob->move(ob, 1);

                write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                return 1;

        case "card":

                if (which != "double" && which != "monthcard" && which != "seasoncard" &&
                    which != "yearcard"  && which != "forevercard")
                {
                        write("û���������͵Ļ�Ա����\n");
                        return 0;
                }


                if (which == "double")
{
ob->set_temp("hyjlexpok",1);
}
                if (which == "monthcard")
{
ob->add("hyday",31);
ob->set("hyvip",1);
}
                else
                if (which == "seasoncard")
{
ob->add("hyday",92);
ob->set("hyvip",2);
}
                else
                if (which == "yearcard")
{
ob->add("hyday",365);
ob->set("hyvip",3);
                        for (i = 0; i < 10; i++)
                        {
                                buy_ob = new("/clone/buy/tishenwawa");
                                buy_ob->move(ob, 1);
                        }


}
                else
                if (which == "forevercard")
{
ob->add("hyday",1800000);
ob->set("hyvip",4);
ob->add("mpgx",88);
                        for (i = 0; i < 10; i++)
                        {
                                buy_ob = new("/clone/buy/tishenwawa");
                                buy_ob->move(ob, 1);
                        }
                                buy_ob = new("/clone/buy/tongren");
                                buy_ob->move(ob, 1);
}
ob->add("hymoney",-value);

if (which != "double")
{
        buy_ob = new("/clone/money/gold");
        tell_object(ob, HIY "������һ�����ƽ�\n" NOR);

        buy_ob->set_amount(10000);
        buy_ob->move(ob,1);
}


                write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                return 1;

        
                
        default:
                write("��Ч��Ʒ���࣡\n");
                return 0;
        }
}


int ask_hy()
{
    string week, month, year, day, time,hydata;
    string check;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx,hylv,cz;
 	object me = this_player();
sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);

if ( !me->query("hyvip"))
{
command("say ��û�л�ԱȨ��!");
        return 1;
}

if ( !me->query("hyday"))
{
command("say ��Ļ�Ա�ʸ��Ѿ�����!");
        return 1;
}

if ( (int)me->query("hyvip") < 1)
{
command("say ��û�л�ԱȨ��!");
        return 1;
}

if ( (int)me->query("hyday") < 1)
{
command("say ��Ļ�Ա�ʸ��Ѿ�����һ����!");
        return 1;
}

if ( (int)me->query("hyday") == 0)
{
command("say ��Ļ�Ա�ʸ��Ѿ�Ϊ����!");
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
command("say ��Ա����һ��ֻ����ȡһ��! "+me->query("name")+"�ϴ���ȡʱ����"+me->query("hydata")+"!");
        return 1;
}



//neili=280+random(888);
exp=30000;
pot=exp/3;
neili=8;
//mpgx=2;

hylv   = (int)me->query("hyvip"); 
exp=exp+(20000*hylv);
pot=exp/3;
if (hylv==1)
{	
pot=pot+(pot*0.3);
neili=neili*2;
mpgx=mpgx*2;
}
if (hylv==2)
{	
pot=pot+(pot*0.6);
neili=neili*3;
mpgx=mpgx*3;
}

	
if (hylv==3)
{	
pot=pot+(pot*0.8);
neili=neili*3;
mpgx=mpgx*3;
}	
	
if (hylv==4)
{	
exp=exp+50000;
pot=pot+pot+20000;
neili=neili*4;
mpgx=mpgx*4;
}

me->add("max_neili",neili);
me->add("combat_exp",exp);
me->add("potential",pot);
//me->add("mpgx",mpgx);
me->set("hydata",hydata);
if ((int)me->query("hyday")<1700000) me->add("hyday",-1);
me->set_temp("hyjlexpok",1);
message_vision(HIC"$n��ȡ��"+ctime(time())+"�Ļ�Ա���� !\n"+me->query("name")+"�ľ�������"+exp+"��Ǳ������"+pot+"�㡣��������"+neili+"�㡣\n"NOR , this_object(), me );
if (me->query("4zhuan")
    || me->query("5zhuan"))
{
if (hylv==4)
{	

cz=1;
me->add("expmax",cz);

message_vision(HIC"$n��ȡ��"+cz+"��ɳ����ޡ�\n"NOR , this_object(), me );


}
}


	return 1;
}

int ask_pk()
{
    string week, month, year, day, time,hydata;
    string check,mt;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
	object *inv;
 	 object target;
 	 	int sizeinv;
 	 	object me = this_player();
target=this_object();
sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);

if(me->is_busy())
{
write("�Բ�������æ����һ�������� ��\n");
                return 1;	
}

		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�㱳�����������Ĺ����͵���ȥ��\n");
       		
		}

if (!wizardp(me) && me->query("combat_exp",1) && me->query("combat_exp",1) < 200000 && me->query("nbjob",1)!=36)
{
write("�Բ�����ľ���̫С���ˣ�ȥ��ս������ ��\n");
                return 1;	
}

if (!wizardp(me) && me->query("combat_exp",1) > 25000000)
{
write("�Բ����������̫ǿ�ˣ���ȥ��������ս��İ� ��\n");
                return 1;	
}

if (!wizardp(me) && me->query_condition("pkjob"))
{
write("�Բ��������ս��������һ�������� ��\n");
                return 1;	
}

hydata=year+month+day;
//write(hydata);

    if ( !wizardp(me) && me->query("pkdata")==hydata && me->query("pktime",1)>3)
{
command("say ÿ����ÿ��ֻ��������ս����!");
        return 1;
}

if ( me->query("pkdata")!=hydata)
{
me->set("pktime",1);	
}
if (!me->query("startroom")) me->set("startroom","/d/city/kedian");

command("say �õģ���ս��ʼ! ������ˣ�������recall ������ĳ����㡣");

if (me->query("combat_exp",1) < 400000)    mt="/d/migong/nlev1/dong21";
if (me->query("combat_exp",1) >= 400000 && me->query("combat_exp",1) < 800000)   mt="/d/migong/nlev2/dong21";
if (me->query("combat_exp",1) >= 800000 && me->query("combat_exp",1) < 1000000) mt="/d/migong/nlev3/dong21";
if (me->query("combat_exp",1) >= 1000000 && me->query("combat_exp",1) <= 2000000) mt="/d/migong/nlev4/dong21";
if (me->query("combat_exp",1) >= 2000000 && me->query("combat_exp",1) <= 2900000) mt="/d/migong/nlev5/dong21";
if (me->query("combat_exp",1) >= 2900000 && me->query("combat_exp",1) <= 3500000) mt="/d/migong/nlev6/dong21";
if (me->query("combat_exp",1) >= 3500000 && me->query("combat_exp",1) <= 4500000) mt="/d/migong/nlev7/dong21";
if (me->query("combat_exp",1) >= 4500000 && me->query("combat_exp",1) <= 5500000) mt="/d/migong/nlev8/dong21";
if (me->query("combat_exp",1) >= 5500000 && me->query("combat_exp",1) <= 6500000) mt="/d/migong/nlev9/dong21";
if (me->query("combat_exp",1) >= 6500000 && me->query("combat_exp",1) <= 9500000) mt="/d/migong/nlev10/dong21";
if (me->query("combat_exp",1) >= 9500000 && me->query("combat_exp",1) <= 12500000) mt="/d/migong/nlev11/dong21";
if (me->query("combat_exp",1)>= 12500000 && me->query("combat_exp",1) <= 14500000) mt="/d/migong/nlev12/dong21";
if (me->query("combat_exp",1)>= 14500000 && me->query("combat_exp",1) <= 17000000) mt="/d/migong/nlev13/dong21";
if (me->query("combat_exp",1)>= 17000000 ) mt="/d/migong/nlev14/dong21";
me->set_temp("nbjob35",1);

me->move(mt);
me->apply_condition("pkjob",50);
me->set("pkdata",hydata);
if (me->query("pktime",1) >3 || !me->query("pktime",1)) 
{
me->set("pktime",1);
}
else
{
me->add("pktime",1);
}
me->start_busy(2);

        return 1;
}



string ask_liwu15()
{
  string msg;
  object ob1;
  object me=this_player();
  int exp_bound,qn_bound,neili;
if (me->query("nbjob",1)<20)
{
	msg=HIY"����˵����\n����ȥ�Ŵ��Ҵ峤��!"NOR;
}

if (me->query("nbjob",1)>=50)
{
	msg=HIY"����˵����\n������ʱûʲô������!"NOR;
}

if (me->query("nbjob")==20)
{
msg=HIY"����˵����\n��һ������
  ��Ϥһ�����ݰ� �ҵ��������� �ҵ����� 
  ���Ժ����Ҫ���������Ǹ��ط�
  ask nan xian about job
  �鿴��ǰ��ͼmap
  ��ɺ� ask beichou about ok"NOR;
me->delete_temp("nbjob19");
me->set_temp("nbjob19",0);
me->delete_temp("nbjob20");
me->set_temp("nbjob20",0);
}
if (me->query("nbjob")==21)
msg=HIY"����˵����\n�ڶ�������
  ��Ϥһ�����ݰ� �ҵ����̺͵�������  
  �Ժ������������������������
  ȥ����� ���� ����к��� ask about job
  �鿴��ǰ��ͼmap
  ��ɺ� ask beichou about ok"NOR;
  
if (me->query("nbjob")==22)
msg=HIY"����˵����\n����������
  ��Ϥһ�����ݰ� �ҵ�������� �ҵ�Ҷ���� 
  �Ժ���Ҫ��Ҷ�������㿴��
  ����к��� ask about job
  �鿴��ǰ��ͼmap
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==23)
msg=HIY"����˵����\n���ĸ�����
  ��Ϥһ�����ݰ� �ҵ�����Ǯׯ �ҵ�Ǯ�ۿ�
  �Ժ���Ҫ��Ǯ�ۿ���Ǯ
  ����к��� ask about job
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==24)
msg=HIY"����˵����\n���������
  ��Ϥһ�´󳵰�  �ҵ��͵�Ĵ�
  ��һ�δ󳵰�
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==25)
msg=HIY"����˵����\n����������
  ��Ϥһ����ǰ�  �ҵ����ݵ����
  ��һ�����
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==26)
msg=HIY"����˵����\n���߸�����
  ��Ϥһ�����ֳ���Ʊ��  �ҵ����ݵ��ӻ���
  ʹ��һ�� ���ֳ���Ʊ
  ��ɺ� ask beichou about ok"NOR;
  
if (me->query("nbjob")==27)
msg=HIY"����˵����\n�ڰ˸�����
  ��10����򵥵����� ĥҩ���� 
  chen job2Ȼ��ask ping about job
  ��ذ���help moyao
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==28)
msg=HIY"����˵����\n�ھŸ�����
  ��10����򵥵����� ��ľ���� 
  chen job3Ȼ��ask songque about job
  ��ذ���help kanshu
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==29)
msg=HIY"����˵����\n��ʮ������
  ��10����򵥵����� ��Ϸ���� 
  chen job4Ȼ��ask guan about job
  ��ذ���help changxi
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==30)
{
msg=HIY"����˵����\n��ʮһ������
  ��һ�δ������� Ҫɱ��ʮ������
  chen job5Ȼ��south ��ɱ�������ý���
  ��ذ���help dalie
  ��ָ����һ���书
  ���: ���ϸ�����ὣ �ľ��� ����һЦ(perform yixiao) 
  ��ɺ� ask beichou about ok"NOR;
if (me->query_skill("jingyiforce",1)<200)
me->set_skill("jingyiforce",200);
if (me->query_skill("softsword",1)<200)
me->set_skill("softsword",200);


}  
if (me->query("nbjob")==31)
msg=HIY"����˵����\n��ʮ��������
  ��1�αȽ��ѵ����� Ѳ������
  chen job7Ȼ��ask wang about job
  ��ذ���help xunchen
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==32)
msg=HIY"����˵����\n��ʮ��������
  ������Ӧ��ѧ����������ˣ����Ҹ����ɼ���ɡ�
  ��ذ���help menpai 
  ���ָ��apprentice ʦ��id
  ��ɺ� ask beichou about ok"NOR;
  
if (me->query("nbjob")==33)
{
msg=HIY"����˵����\n��ʮ�ĸ�����
  ��Ϥһ�´��������� �ҵ���� ȥ�����������
  ��������������ȥ���������� qu dazao
  ���Ѿ�����к�������һ�����Ӿ�����
  ��ذ���help dazao
  ��ɺ� ask beichou about ok"NOR;
if (!me->query_temp("givewq") && !me->query("nbtjob32"))
{
if (!present("qingtong",me))
{
                  ob1=new("/p/item/kuangshi1");
                  ob1->move(me); 
                  ob1=new("/p/item/kuangshi1");
                  ob1->move(me); 
}
if (!present("youyu",me))
{
                  ob1=new("/p/item/material1");
                  ob1->move(me); 
}
me->set_temp("givewq",1);
tell_object(me,HIY"���������һЩ���������Ĳ���!\n"+NOR);
}

}
if (me->query("nbjob")==34)
{
msg=HIY"����˵����\n��ʮ�������
  ��Ϥһ�´��������� �ҵ���� ȥ��������߰�
  ��������������ȥ���������� qu dazao
  ���Ѿ�����к�������һ�����Ӿ�����
  ��ذ���help dazao
  ��ɺ� ask beichou about ok"NOR;
if (!me->query_temp("givefj")  && !me->query("nbtjob33"))
{
if (!present("mianhua",me))
{	
                  ob1=new("/p/item/buliao1");
                  ob1->move(me); 
}
if (!present("qingtong",me))
{
                  ob1=new("/p/item/kuangshi1");
                  ob1->move(me); 
 }
 if (!present("banyu",me))
{	
                  ob1=new("/p/item/material7");
                  ob1->move(me); 
}                  
me->set_temp("givefj",1);
tell_object(me,HIY"���������һЩ������ߵĲ���!\n"+NOR);
}

}
if (me->query("nbjob")==35)
msg=HIY"����˵����\n��ʮ��������
  ��Ϥһ�����ɶ�������� �ҵ����������� 
  ����job��duilian ������Ա Ҫ�����10��
  ��ذ���help geren
  ��ɺ� ask beichou about ok"NOR;
  
if (me->query("nbjob")==36)
msg=HIY"����˵����\n��ʮ�߸�����
  ��һ����ս��������� 
  chen job10Ȼ��ask bei chou about challenge
  ��ذ���help boss ��������-��ս����
  ������뿪 ������recall gc
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==37)
msg=HIY"����˵����\n��ʮ�˸�����
  ��Ϥһ�����ɸ�������� �ҵ����������� 
  ����quest �������Ӧ���� Ҫ�����10��
  ��ذ���help geren
  ��ɺ� ask beichou about ok"NOR;
  
if (me->query("nbjob")==38)
msg=HIY"����˵����\n��ʮ������
  ��ɽ�����������һ�� 
  ����taskjob �ҵ���Ӧ���� ask ���� about job 
  ��ذ���help taskjobs
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==39)
msg=HIY"����˵����\n�ڶ�ʮ����
  �����һ�������һ�� 
  ����hdjob �ҵ���Ӧ��� ask ��� about job 
  ��ذ���help hdjobs
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==40)
msg=HIY"����˵����\n�ڶ�ʮһ����
  �ҵ����ݴ������ �ҵ�Ҷ���� 
  ����Ҫ�����룬ѧ�����ֻش��ļ��ܰ�
  ʹ������ �����ҽ����10��
  ��ذ���help medical
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==41)
msg=HIY"����˵����\n�ڶ�ʮ������
  ���ʮ������������ 
  �ȵ����������ҵ���ɽ��Ȼ���ڵ����ȥ������������������
  ��ذ���help zhaowuqi
  ��ʾ �������ջ񣬿�����Ǯ
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==42)
msg=HIY"����˵����\n�ڶ�ʮ������
  ���ʮ����ũ���� 
  �ȵ����������ҵ�ũׯ��Ȼ��ȥ��ũ
  ��ذ���help zhaoeat
  ��ʾ �������ջ񣬿�����Ǯ
  ��ɺ� ask beichou about ok"NOR;
  
if (me->query("nbjob")==43)
msg=HIY"����˵����\n�ڶ�ʮ������
  ���ʮ���������� 
  �ȵ����������ҵ���Ȫ�Ƽң�Ȼ��ȥ����
  ��ذ���help penlen
  ��ʾ �������ջ񣬿�����Ǯ
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==44)
msg=HIY"����˵����\n�ڶ�ʮ������
  ���ʮ���������� 
  �ȵ����ݸ����ҵ�ҩ�̣�Ȼ�����ҩ��ȥ��ҩ
  ��ҩ���ֺ󣬵�ҩ�������� ����
  ��ذ���help liandan
  ��ʾ �������ջ񣬿�����Ǯ
  ��ɺ� ask beichou about ok"NOR;
  
if (me->query("nbjob")==45)
msg=HIY"����˵����\n�ڶ�ʮ������
  ���ʮ�������������� 
  ȥ�����ҵ����� ���10�α�������
  ���������Ѷ� Ҫ�������һ����ѧ����
  ��ذ���help guojob  [1]��������(����)
  ��ɺ� ask beichou about ok"NOR;

if (me->query("nbjob")==46)
msg=HIY"����˵����\n�ڶ�ʮ������
  ���ʮ�λ������� 
  ȥ�����ҵ����� ���10�γ�������
  ���������Ѷ� Ҫ�������һ����ѧ����
  ��ذ���help huangjob
  ��ɺ� ask beichou about ok"NOR;
  
 if (me->query("nbjob")==47)
msg=HIY"����˵����\n�ڶ�ʮ������
  ���ʮ�λ�������
  �ҵ����ݸ����ھ� ���10�λ�������
  ���������Ѷ� Ҫ�������һ����ѧ����
  ��ذ���help hubiao
  ��ɺ� ask beichou about ok"NOR;
  
if (me->query("nbjob")==48)
msg=HIY"����˵����\n�ڶ�ʮ������
  ����Թ���һ�� 
  ȥ�����������ҵ������� ɱ����һ���BOSS
  ���������Ѷ� Ҫ�������һ����ѧ����
  ��ذ���help migong
  ��ɺ� ask beichou about ok"NOR;
  
if (me->query("nbjob")==49)
msg=HIY"����˵����\n���һ������
  ���һ���������� 
  ȥ���ݹ㳡����������ʿ ���һ����������
  ���������Ѷ� Ҫ�������һ����ѧ����
  �ҵ�һ������ ���黹
  ��ذ���help tasks
  ��ɺ� ask beichou about ok"NOR;
           
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
if (me->query("nbjob",1)==20 && me->query_temp("nbjob19",1)==1)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",21);
return "�������������Ŭ�� ask beichou about job";
}

if (me->query("nbjob",1)==21 && me->query_temp("nbjob20",1)>=2)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",22);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==22 && me->query_temp("nbjob21",1)==1)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",23);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==23 && me->query_temp("nbjob22",1)==1)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",24);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==24 && me->query_temp("nbjob23",1)==1)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",25);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==25 && me->query_temp("nbjob24",1)==1)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",26);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==26 && me->query_temp("nbjob25",1)==1)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",27);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==27 && me->query_temp("nbjob26",1)>=10)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",28);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==28 && me->query_temp("nbjob27",1)>=10)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",29);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==29 && me->query_temp("nbjob28",1)>=10)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",30);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==30 && me->query_temp("nbjob29",1)>=10)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",31);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==31 && me->query_temp("nbjob30",1)>=1)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",32);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==32 && me->query("family/family_name"))
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",33);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==33 && (me->query_temp("nbjob32",1)==1 || me->query("nbtjob32")==1))
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",34);
return "�������������Ŭ�� ask beichou about job";
}

if (me->query("nbjob",1)==34 && (me->query_temp("nbjob33",1)==1 || me->query("nbtjob33")==1))
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",35);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==35 && me->query_temp("nbjob34",1)>=10)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",36);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==36 && me->query_temp("nbjob35",1)==1)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",37);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==37 && me->query_temp("nbjob36",1)>=10)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",38);
return "�������������Ŭ�� ask beichou about job";
}
if (me->query("nbjob",1)==38 && me->query_temp("nbjob37",1)==1)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",39);
return "�������������Ŭ�� ask beichou about job";
}

if (me->query("nbjob",1)==39 && me->query_temp("nbjob38",1)==1)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",40);
return "�������������Ŭ�� ask beichou about job";
}


if (me->query("nbjob",1)==40 && me->query_temp("nbjob41",1)>=10)
{
exp=8888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",41);
return "�������������Ŭ�� ask beichou about job";
}

if (me->query("nbjob",1)==41 && me->query_temp("nbjob42",1)>=10)
{
exp=8888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",42);
return "�������������Ŭ�� ask beichou about job";
}

if (me->query("nbjob",1)==42 && me->query_temp("nbjob43",1)>=10)
{
exp=8888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",43);
return "�������������Ŭ�� ask beichou about job";
}

if (me->query("nbjob",1)==43 && me->query_temp("nbjob44",1)>=10)
{
exp=8888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",44);
return "�������������Ŭ�� ask beichou about job";
}

if (me->query("nbjob",1)==44 && me->query_temp("nbjob45",1)>=10)
{
exp=8888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",45);
return "�������������Ŭ�� ask beichou about job";
}

if (me->query("nbjob",1)==45 && me->query_temp("nbjob46",1)>=10)
{
exp=18888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",46);
return "�������������Ŭ�� ask beichou about job";
}

if (me->query("nbjob",1)==46 && me->query_temp("nbjob47",1)>=10)
{
exp=18888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",47);
return "�������������Ŭ�� ask beichou about job";
}

if (me->query("nbjob",1)==47 && me->query_temp("nbjob48",1)>=10)
{
exp=18888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",48);
return "�������������Ŭ�� ask beichou about job";
}

if (me->query("nbjob",1)==48 && me->query("migong/lev1"))
{
exp=28888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",49);
return "�������������Ŭ�� ask beichou about job";
}

if (me->query("nbjob",1)==49 && me->query_temp("nbjob49",1)>=1)
{
exp=28888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",50);
return "��������������Ӧ����һ�������߽����ˣ� ";
}

  return "���������пն࿴��������Ϣ��(help) �鿴���������� ask beichou about job";
}