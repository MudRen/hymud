// Create by smallfish

#include <ansi.h>
#include <combat.h>
#include <net/dns.h>


inherit F_CLEAN_UP;
string bar_string = "������������������������";
string blank_string = "������������������������";
string blank_string3 = "������������������������";
string blank_string2 = "������������������������";

string age_string(int time)
{
        int month, day, hour, min, sec;
        sec = time % 60;
        time /= 60;
        min = time % 60;
        time /= 60;
        hour = time % 24;
        time /= 24;
        day = time % 30;
        month = time / 30;
        return (month?month + "��":"") + (day?day + "��":"") +
        (hour?hour + "Сʱ":"") + min + "��";
}

int color_len(string str)
{
        int i;
        int extra;

        extra = 0;
        for (i = 0; i < strlen(str); i++)
        {
                if (str[i] == ESC[0])
                {
                        while ((extra++, str[i] < 'A' ||
                                         str[i] > 'z' ||
                                         str[i] > 'Z' && str[i] < 'a') && i < strlen(str))
                                i++;
                }
        }
        return extra;
}



mapping oprank = ([
        "��ʦ"     : HIW "������",
        "�Ƿ��켫" : HIY "������",
        "��������" : HIY "�����  ",
        "��������" : HIR "�����  ",
        "¯����" : HIR "����    ",
        "���д��" : HIC "����    ",
        "��ͬ����" : HIC "���      ",
        "�������" : HIG "���      ",
        "���ֲ���" : HIG "��        ",
        "����С��" : HIM "��        ",
]);

string display_attr(int gift, int value);
string status_color(int current, int max);
string tribar_graph(int val, int eff, int max, string color);
string tribar_graph2(int val, int eff, int max, string color);
string tribar_graph3(int a);
void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob;
        mapping my,mci;
        string line , skill_type,zs,zs1,zs2;
        string hymsg;
        object weapon;
        int jings, qis, j, i, need, lv;
        mixed attack_points, dodge_points, parry_points, btmp,  money,zs3,zs4,money2;
        string jbd, msg;
        int a,b,c,hylv;
        int can_score = 0;
        int age, month;
//        string idx;
        int exp;
        int lvl, level;
        string startroom = "";
        object the_room = 0;

        seteuid(getuid(me));
btmp=1;
if (me->query_temp("nbjob2",1) < 3 || !me->query_temp("nbjob2")) me->add_temp("nbjob2",1);
if (me->query_temp("nbjob2",1)>3) me->set_temp("nbjob2",3);
        if(! arg)
                ob = me;
        else
                ob = present(arg, environment(me));

        if (! ob) ob = find_player(arg);
        if (! ob) ob = find_living(arg);
        if (! ob || ! me->visible(ob)) return notify_fail("��Ҫ�쿴˭��״̬��\n");

        if (wizardp(me) || ob == me) 
                can_score = 1;
        else 
        //if (ob->is_pet() && ob->query("owner") == me->query("id")) 
        //        can_score = 1;
        //els/ 
        if (me->query("couple/couple_id") == ob->query("id"))
                can_score = 1;
        else 
        if (stringp(startroom = ob->query("startroom")) &&
            objectp(the_room = load_object(startroom)) &&
            the_room->query("room_owner_id") == me->query("id"))
                can_score = 0;
        if (! can_score)
                return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

        my = ob->query_entire_dbase();



       if (userp(ob) )
{
exp = (int)ob->query("combat_exp", 1);
level = (int)ob->query("levels", 1);
if (! level || level < 1) 
{
ob->set("levels", 1);
	level = 1;	
}
//tell_object(ob, level);
if (exp> 10000)
{
for (i = level; ;i++) {
if ((i + 1) * (i + 1) * (i + 1) > (exp / 1000))
   {
                                        lvl = i;
                                        break;
   }
}

                
                        if (lvl > level)
                        {
                                j = lvl - level;
                                ob->set("levels", lvl);
                                ob->add("combat_exp", 10000 * j);
                                ob->add("potential", 8000 * j);
                                ob->add("max_neili", 100 * j);
                                if (exp> 600000)  
{
	                        ob->add("mpgx", 10 * j);
                                tell_object(ob, HIY "ֻ��һ�����ɽ�������ڣ��������ȼ�������"+j+"����\n" +
                                        "�˴�������������" + chinese_number(10000 * j) +
                                        "�㾭�顢" + chinese_number(8000 * j) +
                                        "��Ǳ�ܡ�" + chinese_number(100 * j) +
                                        "���������޺�" + chinese_number(10 * j) +
                                        "�����ɹ��ף�\n" NOR);
}
else
{
                                tell_object(ob, HIY "ֻ��һ�����ɽ�������ڣ��������ȼ�������"+j+"����\n" +
                                        "�˴�������������" + chinese_number(10000 * j) +
                                        "�㾭�顢" + chinese_number(8000 * j) +
                                        "��Ǳ�ܡ�" + chinese_number(100 * j) +
                                        "���������ޣ�\n" NOR);

}
                        return notify_fail(HIR"��ĵȼ�������"+j+"����\n"NOR);
                        }
                lv=(int)ob->query("levels", 1);
                need = (lv + 1) * (lv + 1) * (lv + 1) * 1000 - exp;
                if (need < 1) need = 1;

}	       
}
	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
        
        mci = my["combat"];
        if (! mci) mci = ([ ]);
        
//        if (userp(ob) && (! stringp(my["born"]) || ! my["born"])) 
//                return notify_fail("��û�г����ţ��쿴ʲô��\n"); 

        jings = (my["eff_jing"] * 12 / my["max_jing"]) * 2;
        qis = (my["eff_qi"] * 12 / my["max_qi"]) * 2;
        
zs="��";
zs1="��";
zs2="";
if (ob->query("zhuanshen"))
zs="һת";
if (ob->query("zhuanbest"))
zs="��ת";
if (ob->query("4zhuan"))
zs="��ת";
if (ob->query("5zhuan"))
zs="��ת";
if (ob->query("zhuanfinal/7"))
zs1="������ʮ�����졿";
if (ob->query("zhuanfinal/8"))
zs1=zs1+"�������񹦡�";
if (ob->query("zhuanfinal/1"))
zs2="��Ԫ�����";
if (ob->query("zhuanfinal/2"))
zs2=zs2+"����Ӱ���١�";
if (ob->query("zhuanfinal/3"))
zs2=zs2+"����ħ����";
if (ob->query("zhuanfinal/4"))
zs2=zs2+"�����ǲ���";
if (ob->query("zhuanfinal/5"))
zs2=zs2+"����Ԫ�󷨡�";
if (ob->query("zhuanfinal/6"))
zs2=zs2+"����ʿ��˫��";
zs3=6000000+(ob->query("expmax",1)*500000);
if ( ob->query("5zhuan")) 
zs3=5000000+(ob->query("expmax",1)*200000);

zs4=ob->query_temp("menpaijob",1);        
        // line = sprintf("                          ��" + MUD_NAME + "�����˵���                      \n\n", ob->query("language"),);
//if (me->query_temp("xmud")) write("$score");
        line = sprintf( BOLD "\n%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1) );
        // ob->update_age();
        
        line += sprintf( YEL "���������������������������������������ש���������������������������\n" NOR );

        if (userp(ob))
        {
                age = ob->query("age");
                month = ob->query("mud_age");
                if (age >= 60)
                {
                        month -= (age - 60) * 86400 * 4;
                        month = (month - 118 * 86400) / 7200 / 4 + 1;
                } else
                if (age >= 30)
                {
                        month -= (age - 30) * 86400 * 3;
                        month = (month - 28 * 86400) / 7200 / 3 + 1;
                } else
                if (age >= 18)
                {
                        month -= (age - 18) * 86400 * 2;
                        month = (month - 4 * 86400) / 7200 / 2 + 1;
                } else
                {
                        month -= (age - 14) * 86400;
                        month = month / 7200 + 1;
                }

                // not show invalid month
                if (month > 12 || month < 1)
                        month = 1;

                line += sprintf( YEL "��" HIY "�����䡿" NOR "%-24s  " YEL "  ��" NOR ,
                        chinese_number(ob->query("age"))+"��"+chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200 + 1 )+"��");
        } else
                line += sprintf( YEL "��" HIY "�����䡿" NOR "%-24s  " YEL "  ��" NOR , 
                        chinese_number(ob->query("age"))+"��"+chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200 + 1 )+"��"); 
                



        line += sprintf( HIW "��ս����������" NOR " %10d" YEL " ��\n" NOR ,
                attack_points/100 + 1);

        line += sprintf( YEL "��" HIY "���Ա�" NOR "%-26.8s" YEL "  ��" NOR ,
                    ob->query("gender")+ob->query("race"));

                                  
        line += sprintf( HIW "��ս����������" NOR " %10d" YEL " ��\n" NOR ,
                (dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1);

        line += sprintf( YEL "��" HIY "��ת����" NOR "%-28.28s" YEL "��" NOR ,
                zs );
a=ob->query_temp("apply/damage");

if (userp(ob) && ob->query("str") && ob->query("age") >=18)
	{
		
		hylv=ob->query("age",1);
		if (hylv >30) hylv=30;
		c= ob->query("str",1)*hylv;
		if (c>3000) c=3000;
	a += c;
	}

        line += sprintf( HIW "��ս���˺�����" NOR " %10d" YEL " ��\n" NOR ,
                weapon ? a
                               : a);

        line += sprintf( YEL "��" HIY "��������" MAG "%-28.28s" NOR+YEL "��" NOR ,
                CHINESE_D->chinese_date(ob->query("birthday")));
b=ob->query_temp("apply/armor");
if (userp(ob) && ob->query("dex")  && ob->query("age") >=18)
	{
		
		hylv=ob->query("age",1);
		if (hylv >30) hylv=30;
		c= ob->query("dex",1)*hylv;
		if (c>3000) c=3000;
	b += c;
	}
        line += sprintf( HIW "��ս����������" NOR " %10d" YEL " ��\n" NOR ,
                b);

        line += sprintf( YEL "��                          �����������ߩ���������������������������\n" NOR,);      
        if (mapp(my["family"]))
        {
                if( my["family"]["family_name"] )
                        line += sprintf( YEL "��" HIG "�����ɡ�" NOR "%-18.8s" YEL "��" NOR,
                                my["family"]["family_name"] );
                else  
                        line += sprintf( YEL "��" HIG "�����ɡ�" NOR "��ͨ����          " YEL "��" NOR );
        }
        else  
                line += sprintf( YEL "��" HIG "�����ɡ�" NOR "��ͨ����          " YEL "��" NOR );
        line += sprintf( HIY "��������" HIW "%2d |%3d   " HIY "�����ԡ�" HIW "%2d |%3d" NOR+YEL "   ��\n" NOR , 
                ob->query("str"),
                ob->query_str(),
                ob->query("int"), 
                ob->query_int());

        if (mapp(my["family"]))
        {
                if( my["family"]["master_name"] )
                        line += sprintf( YEL "��" HIG "��ʦ�С�" NOR "%-18.18s" YEL "��" NOR,
                                my["family"]["master_name"] );
                else
                        line += sprintf( YEL "��" HIG "��ʦ�С�" NOR "�㻹û�а�ʦ      " YEL "��" NOR );
        }
        else  
                line += sprintf( YEL "��" HIG "��ʦ�С�" NOR "�㻹û�а�ʦ      " YEL "��" NOR );
        line += sprintf( HIY "�����ǡ�" HIW "%2d |%3d   " HIY "������" HIW "%2d |%3d" NOR+YEL "   ��\n" NOR , 
                ob->query("con"),           
                ob->query_con(),
                ob->query("dex"), 
                ob->query_dex());

        if (! ob->query("home"))
                line += sprintf(YEL "��" HIG "��סլ��" NOR "%-18.8s" , "���˽�ͷ");
        else
                line += sprintf(YEL "��" HIG "��סլ��" NOR "%-18.8s" , ob->query("home/home_name") );
        line += sprintf( YEL "��" HIY "����Ե��" HIW "%2d |%3d   " HIY "����ò��" HIW "%2d |%3d" NOR YEL "   ��\n" NOR ,                 ob->query("kar"),           
                ob->query_kar(),
                ob->query("per"), 
                ob->query_per());


        //line += sprintf( YEL "��" HIG "���Ź���" NOR "%-18.18s", chinese_number(my["mpgx"]));
        line += sprintf( YEL "��" HIG "���ȼ���" NOR "%-18.18s", chinese_number(my["levels"]));
        line += sprintf( YEL "��" HIC "��ȭ�š�" NOR "%s" HIC "��������" NOR "%s" NOR YEL "��\n" NOR,HIY+"/cmds/std/looksj.c"->getatt2(ob,1)+NOR+"  ",HIY+"/cmds/std/looksj.c"->getatt3(ob,1)+NOR+"  "); 
        //line += sprintf( YEL "��" HIG "��������" NOR "%-18.18s", chinese_number(zs4));
        line += sprintf( YEL "��" HIG "���Ź���" NOR "%-18.18s", chinese_number(my["mpgx"]));
        line += sprintf( YEL "��" HIC "���ڹ���" NOR "%s" HIC "���Ṧ��" NOR "%s" NOR YEL "��\n" NOR,HIY+"/cmds/std/looksj.c"->getdef(ob,1)+NOR+"  ",HIY+"/cmds/std/looksj.c"->getdog(ob,1)+NOR+"  "); 
        /*
        if (ob->query("is_vendor"))
                line += sprintf(YEL "��" HIG "��ְҵ��" NOR "����              " );
        else
                line += sprintf(YEL "��" HIG "��ְҵ��" NOR "��                " );
        */
        line += sprintf(YEL "��" HIG "��������" NOR "%-10d        ", ob->query("meili"));
        line += sprintf( YEL "��" HIY "�����顿" HIW "%-10d" HIY "��Ǳ�ܡ�" NOR "%s%-10d" NOR YEL "��\n" NOR ,my["combat_exp"],(int)ob->query("potential")>=(int)ob->query_potential_limit()?HIM:HIW,(int)ob->query("potential") - (int)ob->query("learned_points") );
        line += sprintf( YEL "��" HIG "��������" NOR "%-18d" YEL "��" NOR, ob->query("weiwang") );
        line += sprintf( HIY "��%s��" HIW "%-10d" HIY "��������" HIW "%-10d" NOR YEL "��\n" NOR ,(ob->query("shen")>=0)?"����":"а��",ob->query("shen"),ob->query("score") );

        
        if (mapp(my["couple"]))
        {
c=0;
if (ob->is_busy() && !ob->query_temp("pending/exercise")) c=ob->query_busy();

                line += sprintf(YEL "��" HIW "��������" NOR "%-18.8s" , my["couple"]["couple_name"] ? "���" : "ɥż");
                line += sprintf(YEL "��" HIY "����ʦ��" NOR HIW "%-10d" NOR HIY "��æ�ҡ�"NOR HIW "%-10d" NOR YEL "��\n" NOR ,ob->query("betrayer")?ob->query("betrayer"):0,c );
                if (my["couple"]["couple_name"])
                {
                        line += sprintf(YEL "��" HIW "��%s��" NOR "%-18s" YEL "����������������������������������������\n" NOR , "����",my["couple"]["couple_name"] + "(" + my["couple"]["couple_id"]  + ")");
                } else
                {
                        line += sprintf(YEL "��" HIW "�����¡�" NOR "%-18.8s" YEL "����������������������������������������\n" NOR , "û��");
                }                       
                line += sprintf(YEL "��" HIW "����Ů��" NOR "%-56s" NOR YEL "��\n", my["child"] ? "����" : "û��");
        }
        else
        { 
c=0;
if (ob->is_busy() && !ob->query_temp("pending/exercise")) c=ob->query_busy();

                line += sprintf( YEL "��" HIW "��������" NOR "����              " );
                line += sprintf( YEL "��" HIY "����ʦ��" NOR HIW "%-10d" NOR HIY "��æ�ҡ�"NOR HIW "%-10d" NOR YEL "��\n" NOR ,ob->query("betrayer")?ob->query("betrayer"):0,c);
                line += sprintf( YEL "��" HIW "�����¡�" NOR "û��              " YEL "����������������������������������������\n" NOR );
                line += sprintf( YEL "��" HIW "����Ů��" NOR "%-56s" NOR YEL "��\n", "û��" );
        }

        if (my["gender"] == "����")
                line += sprintf( YEL "��" HIW "�����ԡ�" NOR "%-56s" NOR YEL "��\n","̫��" );
        else if (! ob->query("makeloved"))
        {
                if (my["gender"] == "Ů��")
                        line += sprintf( YEL "��" HIW "�����ԡ�" NOR "%-56s" NOR YEL "��\n","��Ů" );
                else
                        line += sprintf( YEL "��" HIW "�����ԡ�" NOR "%-56s" NOR YEL "��\n","ͯ��" );
        }
        line += sprintf(YEL "��" HIW "�����ߡ�" NOR "%-56s" NOR YEL "��\n", mapp(ob->query("guard/active")) ? "ӵ��" : "û��");

        line += sprintf(YEL "��" HIW "�����" NOR "%-56s" NOR YEL "��\n", mapp(ob->query("marks/pet")) ? "ӵ��" : "û��");
        if (ob->query("age")==14) money = 1000;
	if (ob->query("age")>14) money = 1000 + (ob->query("age")-15) * 20;
	if (ob->query("age")>20) money = 2000 + (ob->query("age")-20) * 20;
	if (ob->query("age")>30) money = 4000 + (ob->query("age")-30) * 30;
	if (ob->query("age")>40) money = 8000 + (ob->query("age")-40) * 40;
		
	money2=(int)ob->query("balance",1);
        if (! ob->query("balance"))
                line += sprintf( YEL "��" HIY "��Ǯׯ��" HIY "û�л���                                                " NOR+YEL "��\n" NOR );
        else
        {
                line += sprintf ( YEL "��"  HIY "��Ǯׯ��" NOR );
                line += sprintf (HIY"%-56.56s"NOR,
                MONEY_D->money_str(ob->query("balance")));


//                line += sprintf (HIY"%-56.56s"NOR,
//                chinese_number(money)+"���ƽ�");

                line += sprintf ( NOR+YEL "��\n" NOR );
        }
                if (! ob->query("balance"))
                line += sprintf( YEL "��" HIY "����" HIY "û�л���                                                " NOR+YEL "��\n" NOR );
        else
        {
                line += sprintf ( YEL "��"  HIY "�����ޡ�" NOR );
                line += sprintf (HIY"%-56.56s"NOR,
                chinese_number(money)+"���ƽ�");
                line += sprintf ( NOR+YEL "��\n" NOR );
        }
        
        
if (ob->query_temp("temp_exp"))
{
if (ob->query("mud_age") - ob->query_temp("mud_age") > 1)
{
if (ob->query("combat_exp") > ob->query_temp("temp_exp"))
{
if ((i = (ob->query("combat_exp") - ob->query_temp("temp_exp")) * 60
/ (ob->query("mud_age") - ob->query_temp("mud_age"))) > 100)
i = i*60;

}
}
}        
if (i<0) i=0;
if (i>300000)
{
		i=300000;
		ob->set_temp("mud_age",ob->query("mud_age"));
              }
              if (wizardp(me)) 
              line += sprintf ( YEL "��"  HIY "���ٶȡ�" NOR );
                if (wizardp(me)) line += sprintf (HIY"%-56.56s"NOR,
                chinese_number(i)+"/Сʱ");
                if (wizardp(me)) line += sprintf ( NOR+YEL "��\n" NOR );

        
        //line += sprintf( YEL "��                                                                ��\n" NOR );
        
        /*
        msg = "";
        if (ultrap(ob))
                msg = " ���Ѿ���Ϊ����ʦ";
        if (ob->query("breakup"))
                msg += "����ͨ�ζ�����";
        if (ob->query("animaout"))
                msg += "���޳�ԪӤ����";
        if (ob->query("tianmo_jieti/times"))
                msg += "����ħ����" + chinese_number((int)ob->query("tianmo_jieti/times")) + "��";

        if (msg != "")
        {       
                msg += "��";
                line += sprintf( YEL "��" NOR HIC "%-64s" NOR YEL "��\n" NOR, msg );
                line += sprintf( YEL "��                                                                ��\n" NOR );
        }
        */
        if( my["max_jing"] >= my["eff_jing"])
                line += sprintf( YEL "��" HIC" ��  "NOR"��%-24s   ", tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"])) + tribar_graph3(jings));
        else
                line += sprintf( YEL "��" HIC" ��  "NOR"��%-24s   " , tribar_graph2(my["jing"], my["max_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"]))+ tribar_graph3(jings));

        if( my["max_jingli"] > 0 )
                line += sprintf( HIC "����"NOR"��%-24s"+ NOR+YEL+"��\n"NOR, tribar_graph(my["jingli"], my["max_jingli"], my["max_jingli"], status_color(my["jingli"], my["max_jingli"])));
        else
                line += sprintf( HIC "����"NOR "��" HIG "%-24s"+ NOR+YEL+"��\n"NOR, blank_string );

        if( my["max_qi"] >= my["eff_qi"])
                line += sprintf( YEL "��" HIC" ��  "NOR"��%-24s   ", tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));
        else    
                line += sprintf( YEL "��" HIC" ��  "NOR"��%-24s   ", tribar_graph2(my["qi"], my["max_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));

        if( my["max_neili"] > 0 )
                line += sprintf( HIC "����"NOR"��%-24s"+ NOR+YEL+"��\n"NOR, tribar_graph(my["neili"], my["max_neili"], my["max_neili"], status_color(my["neili"], my["max_neili"])));
        else
                line += sprintf( HIC "����"NOR "��" HIG "%-24s"+ NOR+YEL+"��\n"NOR, blank_string );

        if( ob->max_food_capacity() > 0 )
                line += sprintf( YEL "��" HIC" ʳ��"NOR"��%-24s   ", tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL));
        else
                line += sprintf( YEL "��" HIC" ʳ��"NOR"��"YEL   "%-24s"+ NOR+YEL+"��\n"NOR, blank_string );
        
        if( ob->max_water_capacity() > 0 )
                line += sprintf( HIC "��ˮ"NOR"��%-24s"+ NOR+YEL+"��\n"NOR , tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN));
        else
                line += sprintf( HIC "��ˮ"NOR CYN"��%-24s"+ NOR+YEL+"��\n"NOR, blank_string );

        line += sprintf( YEL "��                                                                ��\n" NOR );
//        line += sprintf( YEL "��" NOR HIY " ��ѧ��ʦ�� %s" NOR HIY "    �ζ������� %s" NOR HIY "   ԪӤ������ %s" NOR HIY "    ת��������%s " NOR YEL "��\n" NOR,
//                userp(ob) ? "��" : HIC "��", ob->query("breakup") ? "��" : HIC "��", ob->query("animaout") ? "��" : HIC "��", ob->query("reborn") ? "��" : HIC "��" );  
        
        line += sprintf( YEL "�ǩ��������������������ש��������������������ש���������������������\n" NOR );        

        line += sprintf( YEL "��" HIC "��ɱ��������" NOR HIR"%6dλ"NOR, 
                my["MKS"] + my["PKS"]);
        line += sprintf( YEL "��" HIC "��ɱ����ҡ�" NOR HIR"%6dλ"NOR, 
                my["PKS"]);
        line += sprintf( YEL "��" HIC "������������" NOR HIR"%6d��"NOR, 
                my["dietimes"]);
        line += YEL "��\n" NOR;

if ( (int)ob->query_condition("bonze_drug" ) > 0 || (int)ob->query_condition("putizi_drug" ) > 0 || (int)ob->query_condition("medicine" ) > 0)
    	msg=HIC"����";
else
    	msg=HIC"����";

    	

    	


        line += sprintf( YEL "��" HIC "��ҩ��ҩ�ԡ�" NOR HIR"%15s"NOR, 
                msg);
if ( (int)ob->query_condition("killer" ) > 0)
    	msg=HIR"����";
else
    	msg=HIR"����";
        line += sprintf( YEL "��" HIC "������ͨ����" NOR HIR"%15s"NOR, 
                msg);

if ( (int)ob->query_condition("psgc" ) > 0)
    	msg=HIW"����";
else
    	msg=HIW"����";  
        line += sprintf( YEL "��" HIC "������׷ɱ��" NOR HIR"%15s"NOR, 
                msg);

        line += YEL "��\n" NOR;

        line += sprintf( YEL "�ǩ��������������������ߩ��������������������ߩ���������������������\n" NOR );
hylv   = (int)ob->query("hyvip"); 
if (hylv==0) hymsg="һ�����";
if (hylv==1) hymsg="������Ա";
if (hylv==2) hymsg="�м���Ա";
if (hylv==3) hymsg="�߼���Ա";		 
if (hylv==4) hymsg="�ǻһ�Ա";
msg=chinese_number(ob->query("hyday"));
if ((int)ob->query("hyday")>=1000000) msg="����";

        line += sprintf( YEL "��" NOR HIB " ��Ա�ȼ���%-53s"NOR YEL "��\n" NOR,
                        hymsg+"("+msg+")" );
        line += sprintf( YEL "��" NOR HIB " ���������%-53s"NOR YEL "��\n" NOR,
                        chinese_number(ob->query("hymoney")) );

        line += sprintf( YEL "��" NOR HIB " ��������%-53d"NOR YEL "��\n" NOR,
                        zs4 );	
        line += sprintf( YEL "��" NOR HIB " �´�������%-53d"NOR YEL "��\n" NOR,
                        need );	

if (ob->query("4zhuan") || ob->query("combat_exp",1) > 90000000)
{
	
	
	        line += sprintf( YEL "��" NOR HIB " �书���ޣ�%-53d"NOR YEL "��\n" NOR,
                        zs3 );	
}
if (ob->query("4zhuan"))
{
	
        line += sprintf( YEL "��" NOR HIB " ת�����ܣ�%-53s"NOR YEL "��\n" NOR,
                        zs2 );	

}
        msg = "";
        if ((int)mci["dietimes"])
                msg = sprintf(HIB " �㵽ĿǰΪֹ�ܹ����ڰ��޳�����"
                                "����%s�Ρ�" NOR,
                                chinese_number(mci["dietimes"]));
        if (msg != "")
                line += sprintf( YEL "��" NOR "%" + sprintf("%d",(64 + color_len(msg))) + "-s" NOR YEL "��\n" NOR, msg );

        msg = "";
        if (stringp(ob->query("killbyname")))
                        msg += sprintf(HIB " �ϴ�����%s" NOR,
                                        ob->query("killbyname"));
 
 
 
        if (msg != "")
                line += sprintf( YEL "��" NOR "%" + sprintf("%d",(64 + color_len(msg))) + "-s" NOR YEL "��\n" NOR, msg );
        line += YEL "���������������������������������������������������������˵���������\n" NOR;
        
        write(line);
write(HIC" "+ob->name()+" ����Ϸ���Ѿ��ȹ���"+age_string((int)ob->query("mud_age"))+"��\n"NOR);
if (wizardp(ob)) write(HIC" "+ob->name()+" ʱ��:"+(int)ob->query("mud_age")+"��\n"NOR);
//if (me->query_temp("xmud")) write("$#\n");
        return 1;
}


string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%6s" NOR, chinese_number(value) );
        else if( value < gift ) return sprintf( CYN "%6s" NOR, chinese_number(value) );
        else return sprintf("%6s", chinese_number(value));
}

string status_color(int current, int max)
{
        int percent;

        if( max ) percent = current * 100 / max;
        else percent = 100;

        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return HIB;
}

string tribar_graph(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*12/max)*2-1]
                + ((eff > val) ? blank_string[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}
string tribar_graph2(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*12/max)*2-1]
                + ((eff > val) ? blank_string2[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}
string tribar_graph3(int a)
{
        return BLU + blank_string3[0..(23-a)] + NOR;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)

���ָ�������ʾ��(��)��ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help setup'��

see also : hp
HELP
    );
    return 1;
}

