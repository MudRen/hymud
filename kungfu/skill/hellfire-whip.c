//�������һ�ޡ�hellfire-whip.c
//write by yesi
/*
�����һ��    dodge  -10    parry  -10    damage  20
�����һ���Ʋ��ƹ��У�һ���������乥����Χ�������⣬
�Ҵ˱�����ת�գ���ȥ���٣�Ҫ�мֵܵ�Ҳ��Ϊ���ס�
�ص���ɱ�˲���

Attention: �����һ��ǰ�����������ֻ��г��ģ�����13��14�����ǿ�ɥ��
�;������У����� Perform �ģ������ƽ���������õ���
*/
inherit SKILL;
#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
int ratio;
string* skill_head =({
        HIB"$N����һ����һ�� ������"NOR,
        HIB"��Ц����$Nһ��������ʹ�� �˼����"NOR,
        HIB"$Nʹ�� ��������"NOR,
        HIB"$N�����﷢���������У�һʽ �����һ�"NOR,
        HIB"$N���ض���������һ�� �����ָ�"NOR,
        HIB"$N����һ����һ�� �زص�î"NOR,
});

string* skill_tail =({
        BLU"������$w���ñ�ֱ������һ����Х�ʹ�$n$l��"NOR,
        BLU"������$w��ž������һȦ��һȦ�ؾ���$n��"NOR,
        BLU"������$w���˸�Ȧ������$n��"NOR,
        BLU"������$w�糤��һ�㣬����$nת����ͣ��"NOR,
        BLU"��$w����$n��$l��"NOR,
        BLU"������$w��Ϧ���Ĵ��̣�����������"NOR,
});


mapping *action = ({
        ([      "name":                 "������",
                "action":
"$N����ϲɫ������$wһӭ��ƮȻ�䡸"+BLINK""+HIY"������"+NOR"������ҵ��ʹ��",
                "dodge":                50,
                "parry":                55,
                "damage":               440,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�˼����",
                "action":
"$N������ݣ�������࣬��������࣬��"+BLINK""+HIG"�˼����"+NOR"��ʹ����Ȼ�����$nΪ֮��Ȼ����",
                "dodge":                110,
                "parry":                55,
                "damage":               345,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��������",
                "action":
"$Nɱ������һ��$w������������ȥ����"+BLINK""+HIM"��������"+NOR"�����������ӵ����쾡��",
                "dodge":                50,
                "parry":                55,
                "damage":               440,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����޵�",
                "action":
"$Nŭ����ڣ�$w��������޵�����$n��������нС�"+BLINK""+HIR"�����޵�"+NOR"��",
                "dodge":                50,
                "parry":                55,
                "damage":               440,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����ָ�",
                "action":
"$N����֮ɫ�������Σ�����֮���᳹��$w��$n�����"+BLINK""+HIB"�����ָ�"+NOR"������",
                "dodge":                50,
                "parry":                55,
                "damage":               450,
                "damage_type":  "����"
        ]),
        ([      "name":                 "����Ͷ̥",
                "action":
"$N�������Σ�˳��һ����$wȴ��ֱ�������$n��ȥ����һ�С�"+BLINK""+YEL"����Ͷ̥"+NOR"��",
                "dodge":                50,
                "parry":                55,
                "damage":               440,
                "damage_type":  "����"
        ]),               
        ([      "name":                 "�����һ�",
                "action":
"$N����һ����һ��"+BLINK""+HIW"���زص�î��"NOR"$w���ñ�ֱ������һ����Х�ʹ�$n$l",
                "dodge":                50,
                "parry":                55,
                "damage":               435,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":               
"$N���һ��������$w�����������ڰ�գ�����"+BLINK""+HIR"����ճ�����"NOR"�����š�\n$nֻ����ȫ�����$w����֮��",
                "dodge":                50,
                "parry":                50,
                "damage":               450,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":
"$N����һ����һ��"+BLINK""+MAG"���������ޡ�"NOR"$w���ض��ɣ��ټ�����ϣ��·�����˵����е��һ𣬼�ͷ���Ե�����$n",
                "dodge":                55,
                "parry":                55,
                "damage":               545,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":
"Ҳ��֪$N��ζ���һ����һ��"+BLINK""+RED"���������жɹ�꡹"NOR"�������������һ����$nֻ��$w�ѻ�����$l",
                "dodge":                55,
                "parry":                55,
                "damage":               535,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":
"$N������ǰ����������$w��ž������һȦ��һȦ�ؾ���$n,��һ��"+BLINK""+HIC"����ڤ������������"NOR"",
                "dodge":                55,
                "parry":                50,
                "damage":               535,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":
"��Ц����$Nһ������������$w���ʣ�������Բ�����ɳ��ʯ�������ݺᣡ\n$n��֪��β���������������������",
                "dodge":                55,
                "parry":                50,
                "damage":               550,
                "damage_type":  "����"
        ]),
        ([      "name":                 "С¥ҹ��",
                "action":
"$N�����﷢���������У��߾�$w������һ�еس���$n��������$n����������\n����$wȴ������Ϣ�ش���$n��$l����������"+BLINK""+HIB"��С¥ҹ�ޡ�"NOR"",
                "dodge":                55,
                "parry":                55,
                "damage":               550,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ع�",
                "action":               "$N������Σ�����ƮƮ�����ĳʱ��̣�һ��"+BLINK""+HIB"����ع���"NOR"����$n$l",
                "dodge":                50,
                "parry":                50,
                "damage":                650,
                "damage_type":  "����"
        ]),

});
string *liudao=({
                HIY"\n$N���г��������������ɵ����������˭����? "NOR,
                HIG"\n$N���г������˽�������˵�����������˭���ˣ�"NOR,
                HIM"\n$N���г�����ڤ�������ծ���������̷�˭������"NOR,
                HIR"\n$N���г��������޵���ɱ¾������ս����˭���磿"NOR,
                HIB"\n$N���г�������������޳�����±�ȸ���˭�Ե���"NOR,
                YEL"\n$N���г����������������������ţ��˭˵�ã�"NOR
                });
                




int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 150 )
                return notify_fail("�������������û�а취�������һ�ޡ�\n");

	if ((me->query_skill("boluomi-hand", 1) < 200) )
		return notify_fail("��Ĳ������ֻ�򲻹���\n");
	if ((me->query_skill("jingang-strike", 1) < 200) )
		return notify_fail("��Ĵ������ƻ�򲻹���\n");
if ((int)me->query_skill("zhanzhuang-gong", 1) < 200)
		 return notify_fail("���վ׮����򲻹����޷�ѧ�������֡�\n");
	if ((me->query_skill("wuxiang-finger", 1) < 200) )
		return notify_fail("��������ָ��򲻹���\n");
	if ((me->query_skill("ruying-leg", 1) < 200) )
		return notify_fail("�����Ӱ�����Ȼ�򲻹���\n");

	if ((me->query_skill("buddha-club", 1) < 100) )
		return notify_fail("����Ͷ������򲻹���\n");
	if ((me->query_skill("lunhui-zhang", 1) < 100) )
		return notify_fail("����ֻط��Ȼ�򲻹���\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ����������һ�ޡ�\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl,j;
         object target;
         mapping pre;
         string *skill, a, b;
        mapping* m_actions;
        string strs;

         
         level   = (int) me->query_skill("hellfire-whip",1);
         lvl = (int)me->query_skill("hellfire-whip", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];

}
                

int practice_skill(object me)
{
        if( (int)me->query("qi") < 35
        ||      (int)me->query("neili") < 50 )
                return notify_fail("�����������������û�а취��ϰ�����һ�ޡ�\n");
        me->receive_damage("qi", 25);
        me->add("neili", -35);
        //write("�㰴����ѧ����һ�������һ�ޡ�\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


string perform_action_file(string action)
{
	return __DIR__"hellfire-whip/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int damage,j;
	int level, jiali, time,level2,damage2;
	object weapon;        
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("zhanzhuang-gong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("hellfire-whip",1))+50;
if (damage > 1600) damage=1600;
if ((random(9)==0 && level2>=250 && me->query_skill_mapped("force") == "zhanzhuang-gong") ||	me->query_temp("ldlh"))
{
        j=random(6);


        message_vision(liudao[j],me);

                switch (j)
                {
                        case 0: {victim->receive_wound("qi",me->query_skill("hellfire-whip")/2+random(me->query_skill("hellfire-whip")/2));
                                 break;
                                }
                        case 1: {victim->receive_wound("jing",me->query_skill("hellfire-whip")/2+random(me->query_skill("hellfire-whip")/2));
                                 break;
                                } 
                        case 2: {victim->add("neili",-(random(me->query_skill("hellfire-whip"))*2+100));
                                 if (!victim->is_busy()) victim->start_busy(3);
                                 break;
                                 }
                        case 3: {victim->add("neili",-me->query_skill("force"));
                                 if (victim->query("neili")<0) victim->set("neili",0);
                                 break;
                                }
                        case 4: {victim->receive_damage("qi",random(me->query_skill("hellfire-whip")));
                                 if (me->query("qi") <= me->query("max_qi")) me->add("qi",random(me->query_skill("hellfire-whip")));
                                 	
                                 break;
                                } 
                        case 5: {victim->receive_damage("jing",random(me->query_skill("hellfire-whip")));
                                 if (me->query("jing") <= me->query("max_jing")) me->add("jing",random(me->query_skill("hellfire-whip")));
                                 if (me->query("neili") <= me->query("max_neili")) me->add("neili",random(me->query_skill("hellfire-whip")));
                                 break;
                                }
                }          
                switch (j)
                {
                        case 0: return HIY"�����ۼ���أ�ϼ�ٺ����Ŀ�����������̱ǣ�˿���������ڶ���$n�������ж���֪����\n"NOR;
                        case 1: return HIG"$n�����������������ů��������ϣ�������Ȼ��\n"NOR;
                        case 2: return HIM"$n������˺���ѷεĽк�����Χ���ŵû���ֱð�亹��\n"NOR;
                        case 3: return HIR"$n�����ķ�����������׷ɱ��ʧ����������ƣ���ߡ�\n"NOR;
                        case 4: return HIB"$n������������Ӹо��Լ��ĺ���Ҳ���ճ�ֻ��һ��ϸ�첻�ܽ�ʳ��\n"NOR;
                        case 5: return YEL"$n��̾�����������֪�Ϳ�������֪�����͵������г̡�\n"NOR;
               }
        
        }

else
{	
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("hellfire-whip",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}
}


mixed fail_hit(object me, object victim)
{    
        if (me->query_temp("ldlh"))
        {
                switch (me->query_temp("lunhui")%6)
                {
                        case 1: return HIC"$n��Ϊ������ʥ�����������ս����񣬵�ָ�����������ȥ��\n"NOR;
                        case 2: return HIC"$nӲ���ĳ����������Ե����ǷǷǣ��첽�뿪�˽����\n"NOR;
                        case 3: return HIC"$n�ԲҺ�����м�ڹˣ���֮߮��ʤ����ͥ�Ų���\n"NOR;
                        case 4: return HIC"$n�Ը������������࣬�ܿ��ɱ��һ��Ѫ·�뿪�ˡ�\n"NOR;
                        case 5: return HIC"$n����һ��Ⱥ�����ԶԶ�Ķ��˿�ȥ��\n"NOR;
                        case 0: return HIC"$n������һƥ������������ҹ����뿪������硣\n"NOR;
                        //default: return 1;
                }
        }   
}      

mixed hit_ob_msg(object me,object victim)
{   
        string strs;
        if (me->query_temp("ldlh"))
        {
                //me->add_temp("lunhui",1);
                switch (me->query_temp("lunhui")%6)
                {
                        case 1: return HIY"�����ۼ���أ�ϼ�ٺ����Ŀ�����������̱ǣ�˿���������ڶ���$n�������ж���֪����\n"NOR;
                        case 2: return HIG"$n�����������������ů��������ϣ�������Ȼ��\n"NOR;
                        case 3: return HIM"$n������˺���ѷεĽк�����Χ���ŵû���ֱð�亹��\n"NOR;
                        case 4: return HIR"$n�����ķ�����������׷ɱ��ʧ����������ƣ���ߡ�\n"NOR;
                        case 5: return HIB"$n������������Ӹо��Լ��ĺ���Ҳ���ճ�ֻ��һ��ϸ�첻�ܽ�ʳ��\n"NOR;
                        case 0: return YEL"$n��̾�����������֪�Ϳ�������֪�����͵������г̡�\n"NOR;
               }
       }
}        

