// hanbing-zhenqi.c ��������

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
       if ((int)me->query_skill("force", 1) < 50)
               return notify_fail("��Ļ����ڹ���򻹲�����\n");
if (
	me->query_skill("bahuang-gong",1)
|| me->query_skill("xuantian-wuji",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("taiji-shengong",1)||
me->query_skill("guiyuan-tunafa",1)||
me->query_skill("kongdong-xinfa",1)||
me->query_skill("taixuan-gong",1)||
me->query_skill("bitao-shengong",1)||
me->query_skill("jinghai-force",1)||
me->query_skill("wuzheng-xinfa",1)||
me->query_skill("lengyue-shengong",1)||
me->query_skill("huiyan-xinfa",1)||
me->query_skill("baiyun-xinfa",1)||
me->query_skill("panshi-shengong",1)||
me->query_skill("qingming-xuangong",1)||
me->query_skill("bluesea-force",1)||
me->query_skill("honghua-shengong",1)
 )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ����\n");
       return 1;
}

int practice_skill(object me)
{
	return notify_fail("��������ֻ�ܿ�ѧ(learn)����ߡ�\n");


}

string exert_function_file(string func)
{
       return __DIR__"hanbing-zhenqi/" + func;
}

mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIW + me->name()+"���Ϻ������֣�������΢��������" NOR,
    "start_my_msg" : "�����󽣾���������������������������ת����\n",
    "start_other_msg" : me->name()+"���˸���ϥ���������ƣ�ȫ��������һƬ����֮�С�\n",
    "halt_msg" : "$N˫��һ��������ѹ����Ϣվ��������\n",
    "end_my_msg" : HIW"�㽫��������������֮�ư�����һ�ܣ��о����������ˡ�\n"NOR,
    "end_other_msg" : HIW"ֻ��"+me->name()+"��������˫��վ�𣬻���ɢ����һ�ɱ���ĺ�����\n"NOR,
    "heal_msg" : HIW"$N���𺮱���������ʼ�����������ˡ�\n"NOR,
    "heal_finish_msg" : HIY"$N��Ϣһͣ��ȴ�������Ѿ�ȫ���ˡ���\n"NOR,
    "heal_unfinish_msg" : "$Nüͷһ�壬���ۡ����³�һ����Ѫ���������˻�û��ȫ�á�\n",
    "heal_halt_msg" : "$N��������Ϣһѹ��Ҳ�������ϵ���������վ��������\n",
    ]);
}

int ob_hit(object ob, object me, int damage)
{
        string msg;
        int skill, neili, neili1;
        object weapon;
        skill = me->query_skill("hanbing-zhenqi", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        if(living(me)  &&
        !objectp(weapon = ob->query_temp("weapon")) &&
        random(skill)+10 > ob->query_skill("parry", 1)/2 && 
        me->query("combat_exp") > ob->query("combat_exp")/2 && 
        ob->query_skill_mapped("force") != "hanbing-zhenqi" &&
        skill > 180 && 
        neili > 500 && 
        living(ob) &&        
        !ob->query("env/invisibility"))
        {
                if(random(ob->query_skill("force")) < me->query_skill("force")/2)
                {
                        msg = HIW"��Ȼ$n���һ����æ���֣�";         
                        if(neili > neili1*2 )
                        {
                                msg += "ȫ���Ѿ������ֱ��ս���������ã�\n"NOR;
                                if(random(ob->query_skill("force")) < 150)
                                        ob->apply_condition("cold_poison", ob->query_condition("cold_poison") + random(4));
                                ob->start_busy(1+random(4));
                        }
        
                        else if(neili > neili1 )
                        {
                                msg += "ȴ����ȫ��������һ�����\n"NOR;
                                ob->apply_condition("cold_poison", ob->query_condition("cold_poison") + random(4));
                        }
                
                        else if(neili > neili1/3*2 )
                        {
                                msg += "���������˱���һ����\n"NOR;
                                ob->start_busy(random(2));
                        }
                        else msg += "ȴ�������Ѿ�������һ�㱡˪��\n"NOR;
                        
                        damage = -skill*3;
                        message_vision(msg, me, ob);
                }
                
                else if( random(100) >= 90 && neili > neili1)
                {
                        message_vision(HIW"˭֪��һ�Ӵ���$P������һ�ɼ���֮���������ŵ�$n��æ�վ����֣�\n"NOR, me, ob);
                        damage = -8000;
                }       
                
                else
                {
                        message_vision(HIW"˭֪��һ�Ӵ�����һ�ɺ����������ŵ�$n��æ�վ����֣�\n"NOR, me, ob);
                        damage = -skill;
                }
                
                return damage;
       }
}
