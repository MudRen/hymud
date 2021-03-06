
#include <ansi.h>
#include <combat.h>



inherit F_SSERVER;

string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe", "throwing"
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string skill_enables(object sk);
mapping valid_type = ([
"unarmed":      "拳脚",
"claw":         "爪功","cuff":         "拳功",
"finger":       "指功","strike":       "掌功",
"hand":         "手功","leg":          "腿功",
"sword":        "剑法","blade":        "刀法",	
"dagger":       "匕法","brush":        "笔法",		
"spear":        "枪法","hook":         "钩法",		
"stick":        "棒法","staff":        "杖法",		
"club" :        "棍法","throwing":     "暗器",		
"whip":         "鞭法","axe":          "斧法",
"hammer":       "锤法","force":        "内功",	
"dodge":        "轻功","parry":        "招架",	
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
        if (!read_file(filen))  write_file(filen, "招名 无\n出招 无\n中招 无\n未中 无", 1);
        //mission=base_name(oldob);
        wmission = explode(read_file(filen), "\n");

for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wmin,wname)!=2 ) continue;
        if (wmin=="招名")        pfm=wname;
        if (wmin=="出招")        fz1=wname;
        if (wmin=="中招")        fz2=wname;
        if (wmin=="未中")        fz3=wname;

        }
fz1= replace_string(fz1, "'"," ");
fz1= replace_string(fz1, "你","$N");
fz1= replace_string(fz1, "小鱼儿","$n");               
fz2= replace_string(fz2, "'"," ");
fz2= replace_string(fz2, "你","$N");
fz2= replace_string(fz2, "小鱼儿","$n");               
fz3= replace_string(fz3, "'"," ");
fz3= replace_string(fz3, "你","$N");
fz3= replace_string(fz3, "小鱼儿","$n");               



        
        
        if (!pfm || pfm=="无")
                return notify_fail("请先设定(selfpf)你这个绝招的名称。\n");
        
        if (!fz1 || fz1=="无")
        fz1=HIC "$N" HIC "面容肃穆，倏的一招使出，虚虚实"
              "实的攻向$n" HIC "，变化令人难以捉摸。\n" NOR;
        if (!fz2 || fz2=="无")
        fz2=HIR "$n" HIR "稍一犹豫，被这一招击了"
                                           "个正中！接连退了几步，吐了一地的血。\n" NOR;
        if (!fz3 || fz3=="无")
        fz3= HIG "然而$n" HIG "看破了$N" HIG
                       "的招式，不慌不忙的躲过了这一击！\n" NOR;
                       
lv=(int)me->query_skill(file, 1);
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail( "只能对战斗中的对手使用。\n");

        if (me->query_skill_mapped("parry") != file)
                return notify_fail("你现在没有激发这个武功为招架。\n");

        if (me->query_skill_mapped(bk) != file)
                return notify_fail("你现在没有激发这个武功。\n");

        if (member_array(bk, weapon_sk) != -1)
        {
                if (! objectp(weapon = me->query_temp("weapon"))
                   || (string)weapon->query("skill_type") != bk)
                        return notify_fail("你所使用的武器不对，难以施展 。\n");
        } else
        {
                if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        return notify_fail( "只能空手使用。\n");             
        }
        
        if ((int)me->query_skill(file, 1) < 400)
                return notify_fail("你" + to_chinese(file) + "不够娴熟，难以施展  。\n");


        if (member_array(bk, weapon_sk) == -1)
        {
                if (me->query_skill_prepared(bk) != file)
                        return notify_fail("你没有准备" + to_chinese(file) + "，难以施展  。\n");
        }
        
        if (me->query("neili") < 800)
                return notify_fail("你现在的真气不够，难以施展  。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR+ "$N使出了自创绝技:"+pfm + "\n" + NOR;
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
	msg +=RED"$N使用了斩仙决!!$n突然胸口一痛鲜血狂奔!\n"NOR;
}
else
if (me->query("zhuanfinal/2") ==1 && random(3)==0)
{
	if (userp(target))
	target->add("neili", -target->query("neili")/8);
        if (!userp(target))
         target->add("neili", -500);
	msg +=HIY"$N使用了破仙决!!$n突然内力消失!\n"NOR;
}
else
if (me->query("zhuanfinal/3") ==1 && random(3)==0)
{
	if (!target->is_busy())
	target->start_busy(4);
	msg +=HIY"$N使用了乱仙决!!$n突然手忙脚乱!\n"NOR;
}
if (me->query("zhuanfinal/4") ==1 && random(3)==0)
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);
                if (me->query("qi") < me->query("max_qi") )

	msg += HIY"$N使用了妙仙决!!$N全身的伤好了很多!\n"NOR;
}
else
if (me->query("zhuanfinal/5") ==1 && random(3)==0)
{
if (me->is_busy() )
me->start_busy(1);
if (!target->is_busy() )
target->start_busy(2);
	msg += HIY"$N使用了动仙决!!$N突然动作又快了!\n"NOR;
}
else
if (me->query("zhuanfinal/6") ==1 && random(3)==0)
{
                if (me->query("neili") < me->query("max_neili") )
                me->add("neili", me->query("max_neili") / 8);
	msg += HIY"$N使用了银仙决!!$N突然内力恢复了!\n"NOR;
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
	//str = "│"HIY"特殊技能"NOR"：\t\t\t\t\t\t\t    ";
		
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
	//str += "│\n";
	return str;
}