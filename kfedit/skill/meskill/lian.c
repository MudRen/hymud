
#include <ansi.h>
#include <combat.h>



inherit F_SSERVER;

string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe", "throwing"
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string skill_enables(object sk);
mapping valid_type = ([
"unarmed":      "ȭ��",
"claw":         "צ��","cuff":         "ȭ��",
"finger":       "ָ��","strike":       "�ƹ�",
"hand":         "�ֹ�","leg":          "�ȹ�",
"sword":        "����","blade":        "����",	
"dagger":       "ذ��","brush":        "�ʷ�",		
"spear":        "ǹ��","hook":         "����",		
"stick":        "����","staff":        "�ȷ�",		
"club" :        "����","throwing":     "����",		
"whip":         "�޷�","axe":          "����",
"hammer":       "����","force":        "�ڹ�",	
"dodge":        "�Ṧ","parry":        "�м�",	
]);

int perform(object me, object target,string file)
{
        object weapon,sk;
        string msg,pfm,bk,fz1,fz2,fz3,filen;
        int ap, dp;
        int count;
        int i, attack_time,lv;
        string mission, wname, wmin,mission2;
        string *wmission;
        object newob,oldob;
        sk = load_object(SKILL_D(file));
        bk=skill_enables(sk);
        
 filen = "/p/skill/"+file+"lian";
        if (!read_file(filen))  write_file(filen, "���� ��\n���� ��\n���� ��\nδ�� ��", 1);
        //mission=base_name(oldob);
        wmission = explode(read_file(filen), "\n");

for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wmin,wname)!=2 ) continue;
        if (wmin=="����")        pfm=wname;
        if (wmin=="����")        fz1=wname;
        if (wmin=="����")        fz2=wname;
        if (wmin=="δ��")        fz3=wname;

        }
fz1= replace_string(fz1, "'"," ");
fz1= replace_string(fz1, "��","$N");
fz1= replace_string(fz1, "С���","$n");               
fz2= replace_string(fz2, "'"," ");
fz2= replace_string(fz2, "��","$N");
fz2= replace_string(fz2, "С���","$n");               
fz3= replace_string(fz3, "'"," ");
fz3= replace_string(fz3, "��","$N");
fz3= replace_string(fz3, "С���","$n");               



        
        
        if (!pfm || pfm=="��")
                return notify_fail("�����趨(selfpf)��������е����ơ�\n");
        
        if (!fz1 || fz1=="��")
        fz1=HIC "$N" HIC "�������£�ٿ��һ��ʹ��������ʵ"
              "ʵ�Ĺ���$n" HIC "���仯��������׽����\n" NOR;
        if (!fz2 || fz2=="��")
        fz2=HIR "$n" HIR "��һ��ԥ������һ�л���"
                                           "�����У��������˼���������һ�ص�Ѫ��\n" NOR;
        if (!fz3 || fz3=="��")
        fz3= HIG "Ȼ��$n" HIG "������$N" HIG
                       "����ʽ�����Ų�æ�Ķ������һ����\n" NOR;
                       
lv=(int)me->query_skill(file, 1);
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail( "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill_mapped("parry") != file)
                return notify_fail("������û�м�������书Ϊ�мܡ�\n");

        if (me->query_skill_mapped(bk) != file)
                return notify_fail("������û�м�������书��\n");

        if (member_array(bk, weapon_sk) != -1)
        {
                if (! objectp(weapon = me->query_temp("weapon"))
                   || (string)weapon->query("skill_type") != bk)
                        return notify_fail("����ʹ�õ��������ԣ�����ʩչ ��\n");
        } else
        {
                if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        return notify_fail( "ֻ�ܿ���ʹ�á�\n");             
        }
        
        if ((int)me->query_skill(file, 1) < 400)
                return notify_fail("��" + to_chinese(file) + "������죬����ʩչ  ��\n");


        if (member_array(bk, weapon_sk) == -1)
        {
                if (me->query_skill_prepared(bk) != file)
                        return notify_fail("��û��׼��" + to_chinese(file) + "������ʩչ  ��\n");
        }
        
        if (me->query("neili") < 800)
                return notify_fail("�����ڵ���������������ʩչ  ��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR+ "$Nʹ�����Դ�����:"+pfm + "\n" + NOR;
        msg += HIW+ fz1 + "\n" + NOR;

        ap = me->query_skill(file);
        dp = target->query_skill("parry");
        attack_time = 6;

        if (ap * 2 / 3 + random(ap) > dp)
        {
                msg += HIM +fz2 + "\n" NOR;
                count = ap / 20;

        } else
        {
                msg += NOR + CYN +fz3 + "\n" NOR;
                count = 0;
        }


        attack_time += me->query_skill(file,1)/100;
        if (attack_time > 15)
                attack_time = 15;

        me->add("neili", -attack_time * 20);
if (count>200) count=200;

          

                me->add_temp("apply/attack", count);
                me->add_temp("apply/damage", (count*10));

        for (i = 0; i < attack_time; i++)
        {
lv=random(lv);

                if (random(2) && ! target->is_busy()) target->start_busy(2);

       msg = order[random(13)]+SKILL_D(file)->query_skill_name(lv)+NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -(count*10));

if (me->query("zhuanfinal/1") ==1 && random(3)==0)
{
	if (userp(target))
	target->receive_wound("qi", target->query("qi")/8);
        if (!userp(target))
         target->receive_wound("qi", 800,me);
	msg +=RED"$Nʹ����ն�ɾ�!!$nͻȻ�ؿ�һʹ��Ѫ��!\n"NOR;
}
else
if (me->query("zhuanfinal/2") ==1 && random(3)==0)
{
	if (userp(target))
	target->add("neili", -target->query("neili")/8);
        if (!userp(target))
         target->add("neili", -500);
	msg +=HIY"$Nʹ�������ɾ�!!$nͻȻ������ʧ!\n"NOR;
}
else
if (me->query("zhuanfinal/3") ==1 && random(3)==0)
{
	if (!target->is_busy())
	target->start_busy(4);
	msg +=HIY"$Nʹ�������ɾ�!!$nͻȻ��æ����!\n"NOR;
}
if (me->query("zhuanfinal/4") ==1 && random(3)==0)
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);
                if (me->query("qi") < me->query("max_qi") )

	msg += HIY"$Nʹ�������ɾ�!!$Nȫ����˺��˺ܶ�!\n"NOR;
}
else
if (me->query("zhuanfinal/5") ==1 && random(3)==0)
{
if (me->is_busy() )
me->start_busy(1);
if (!target->is_busy() )
target->start_busy(2);
	msg += HIY"$Nʹ���˶��ɾ�!!$NͻȻ�����ֿ���!\n"NOR;
}
else
if (me->query("zhuanfinal/6") ==1 && random(3)==0)
{
                if (me->query("neili") < me->query("max_neili") )
                me->add("neili", me->query("max_neili") / 8);
	msg += HIY"$Nʹ�������ɾ�!!$NͻȻ�����ָ���!\n"NOR;
}      
       message_vision(msg, me, target);
        me->start_busy(2 + random(attack_time/ 3));

        return 1;
}


string skill_enables(object sk)
{
	int i, j;
	string str, *skills;
	skills = keys(valid_type);
	
	for(i=0; i < sizeof(skills); i++) {
		if (sk->valid_enable(skills[i])) continue;
		skills[i] = 0;
	}
	
	skills -= ({ 0 });
	j = sizeof(skills);
	if( !j || j < 1)
		return "";
	//str = "��"HIY"���⼼��"NOR"��\t\t\t\t\t\t\t    ";
		
	for(i=0; i < j; i++) {
		if (i % 4 == 0) str = "";
		if (skills[i]!="parry")	str = sprintf(skills[i]);
		if ( i > j-2 ){
			switch(i%4){
				//case 0: str +="\t\t\t\t\t            "; break;
				//case 1: str +="\t\t\t            "; break;
				//case 2: str +="\t\t    "; break;
				default: break;
			}
                }
	}
	//str += "��\n";
	return str;
}