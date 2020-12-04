//huanhe-dao.c.ìÓºÕµ¶
//date:1997.9.11
//by dan
#include <ansi.h>     
inherit SKILL;

mapping * action=({
    ([  "action":
"$N³åÌì¶øÆğ£¬Ò»ÕĞ¡¸Îâ¹³ËªÑ©Ã÷¡¹£¬$w´ø×ÅÁèÀ÷µÄ·çÉùÕ¶Ïò$nµÄÍ·²¿",
        "lian"  :
"$N³åÌì¶øÆğ£¬Ò»ÕĞ¡¸Îâ¹³ËªÑ©Ã÷¡¹£¬$w´ø×ÅÁèÀ÷µÄ·çÉùÔÚ¿ÕÖĞ·ÉÎè¡£",
        "sen"   :8,
        "jibie" :5,
        "dodge" :20,
        "parry" :20,
        "damage" :330,
        "zhaoshi" : "¡¸Îâ¹³ËªÑ©Ã÷¡¹",
        "damage_type":"¸îÉË"
        ]),
 ([  "action":
"$N±©ºÈÒ»Éù£¬Ê¹³öÒ»ÕĞ¡¸½«ÖËà¢Öìº¥¡¹£¬ÒÔµ¶µ±½££¬$wÉÁµç°ã´ÌÏò$nµÄĞØ¡£",
        "lian"  :
"$N±©ºÈÒ»Éù£¬Ê¹³öÒ»ÕĞ¡¸½«ÖËà¢Öìº¥¡¹£¬ÒÔµ¶µ±½££¬$wÉÁµç°ã´Ì³ö¡£",
        "sen"   :9,
        "jibie" :3,
        "dodge" :25,
        "parry" :15,
        "damage" :330,
        "zhaoshi" : "¡¸½«ÖËà¢Öìº¥¡¹",
        "damage_type":"¸îÉË"
        ]),  
 ([     "action":
"$NÊ¹³öÒ»ÕĞ¡¸Èı±­ÍÂÈ»Åµ¡¹£¬ÉíĞÎÈç×í¾ÆÒ»°ã£¬ÊÖÖĞ$wÔÓÂÒÎŞÕÂµØÏò$nÅüÈ¥¡£",
        "lian"  :
"$NÊ¹³öÒ»ÕĞ¡¸Èı±­ÍÂÈ»Åµ¡¹£¬ÉíĞÎÈç×í¾ÆÒ»°ã£¬ÊÖÖĞ$w¸üÊÇÔÓÂÒÎŞÕÂ¡£",
        "sen"   :10,
        "jibie" :40,
        "dodge" :30,
        "parry" :0,
        "damage" :340,
        "zhaoshi" : "¡¸Èı±­ÍÂÈ»Åµ¡¹",
        "damage_type":"¸îÉË"
        ]),
  ([    "action":
"$N²»ÊØ·´¹¥£¬Ò»Ê½¡¸¾ÈÕÔ»Ó½ğ´¸¡¹ÊÖÖĞ$wÈçÍ¬¿ªÉ½¾Ş¸«Ò»°ãÏò$nµÄ$l¿³È¥¡£",
        "lian"  :
"$N²»ÊØ·´¹¥£¬Ò»Ê½¡¸¾ÈÕÔ»Ó½ğ´¸¡¹ÊÖÖĞ$wÈçÍ¬¿ªÉ½¾Ş¸«Ò»°ã»ô»ôÉú·ç¡£",
        "sen"   :11,
        "jibie" :60,
        "dodge" :0,
        "parry" :30,
        "damage" :250,
        "zhaoshi" : "¡¸¾ÈÕÔ»Ó½ğ´¸¡¹",
        "damage_type":"¸îÉË"
        ]),
   ([  "action":
"$N²Øµ¶ÄÚÊÕ£¬µ¶¹âÈçÂÖ¼²×ª£¬Ò»ÕĞ¡¸²»²ÑÊÀÉÏÓ¢¡¹£¬$w¾íÏò$nµÄ$l¡£",
        "lian"  :
"$N²Øµ¶ÄÚÊÕ£¬µ¶¹âÈçÂÖ¼²×ª£¬ÕıÊÇÒ»ÕĞ¡¸²»²ÑÊÀÉÏÓ¢¡¹¡£",
        "sen"   :12,
        "jibie" :80,
        "dodge" :10,
        "parry" :30,
        "damage" :250,
        "zhaoshi" : "¡¸²»²ÑÊÀÉÏÓ¢¡¹",
        "damage_type":"¸îÉË"
        ]),
    ([  "action":
"$NÍ»È»ÆËµ½$nµÄÃæÇ°£¬Ò»ÕĞ¡¸Ë­ÄÜÊé¸óÏÂ¡¹£¬$wÎŞÉùÎŞÏ¢µØÅüÏò$n",
        "lian"  :
"$NÍ»È»ÏòÇ°Ò»ÆË£¬Ò»ÕĞ¡¸Ë­ÄÜÊé¸óÏÂ¡¹£¬$wÎŞÉùÎŞÏ¢µØÅü³ö¡£",
        "sen"   :12,
        "jibie" :100,
        "dodge" :30,
        "parry" :30,
        "damage" :360,
        "zhaoshi" : "¡¸Ë­ÄÜÊé¸  óÏÂ¡¹",
        "damage_type":"¸îÉË"
        ]),
});
string *parry_msg = ({
    "$nÒ»¶¶$v£¬Ò»ÕĞ¡¸½«ÖËà¢Öìº¥¡¹£¬ÊÖÖĞµÄ$v»¯×÷Ò»Ìõ³¤ºç£¬¿Ä¿ªÁË$PµÄ$w¡£\n",
    "$nÒ»ÕĞ¡¸Èı±­ÍÂÈ»Åµ¡¹½«ÊÖÖĞµÄ$vÎèµÃÃÜ²»Í¸·ç£¬·â×¡ÁË$NµÄ¹¥ÊÆ¡£\n",
    "$pÊ¹³öÒ»ÕĞ¡¸¾ÈÕÔ»Ó½ğ´¸¡¹£¬ÊÖÖĞµÄ$v»¯×öÂşÌìÑ©Ó°£¬µ´¿ªÁË$NµÄ$w¡£\n",
    "$n·´ÊÖÒ»ÕĞ¡¸²»²ÑÊÀÉÏÓ¢¡¹£¬Õû¸öÈËÏûÊ§ÔÚÒ»ÍÅ¹âÃ¢Ö®ÖĞ¡£\n",
    "$pÊ¹³öÒ»ÕĞ¡¸Îâ¹³ËªÑ©Ã÷¡¹£¬$wÖ±´Ì$NµÄË«ÊÖ¡£\n",
    "$pÇ°¿çÒ»²½£¬Ò»ÕĞ¡¸Ë­ÄÜÊé¸óÏÂ¡¹£¬$wÅüÏò$NµÄĞØ¿Ú¡£\n",
});

string *unarmed_parry_msg = ({
    "$nË«È­Æë³ö£¬Ò»ÕĞ¡¸¾ÈÕÔ»Ó½ğ´¸¡¹£¬ÃÍ»÷$NµÄÃæÃÅ£¬±ÆµÃ$NÖĞÍ¾³·»Ø$w¡£\n",
    "$n½Å×ßÒõÑô£¬Ò»ÕĞ¡¸½«ÖËà¢Öìº¥¡¹£¬¹¥$NÖ®±Ø¾È¡£\n",
    "$nË«ÊÖÎèµÃÃÜ²»Í¸·ç£¬Ê¹³ö¡¸Èı±­ÍÂÈ»Åµ¡¹£¬·â×¡ÁË$NµÄ¹¥ÊÆ¡£\n",
    "$nÉíĞĞÆ®ºö£¬Ê¹³ö¡¸²»²ÑÊÀÉÏÓ¢¡¹£¬±Ü¿ªÁË$NµÄÕâÒ»ÕĞ¡£\n",
    "µ«¼û$nÒ»ÕĞ¡¸Îâ¹³ËªÑ©Ã÷¡¹£¬ÆÈµÃ$NÁ¬Á¬ºóÍË¡£\n",
    "$nÊ¹³öÒ»ÕĞ¡¸Ë­ÄÜÊé¸óÏÂ¡¹£¬»º»ºÍÆÏò$NµÄ$l¡£\n",
});
     


string query_parry_msg(object weapon)
{   
    if ( objectp( weapon ) )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");

        if ((int)me->query_skill("taixuan-gong", 1) < 100)
                return notify_fail("ÄãµÄÌ«ĞşÉñ¹¦»ğºòÌ«Ç³¡£\n");
 	if(me->query_skill("xiuli-qiankun", 1) < 250)
		return notify_fail("ÄãµÄĞäÀïÇ¬À¤ĞŞÎª²»¹»£¬ÎŞ·¨ĞŞÁ¶¡£\n");
        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("Äã¾õµÃìÓºÕµ¶Éî°ÂÖ®¼«£¬Ò»Ê±¼äÄÑÒÔÁì»á¡£\n");

	if(me->query_skill("wuyu-quan", 1) < 250)
		return notify_fail("ÄãµÄÎåÓüÈ­ĞŞÎª²»¹»£¬ÎŞ·¨ĞŞÁ¶¡£\n");

	if(me->query_skill("sata-shenfa", 1) < 250)
		return notify_fail("ÄãµÄìªí³Éí·¨ĞŞÎª²»¹»£¬ÎŞ·¨ĞŞÁ¶¡£\n");

		
if (me->query_skill("huanhe-dao", 1) > 251)
{
			if(me->query_skill("sumi-jian", 1) < me->query_skill("huanhe-dao", 1))
		return notify_fail("ÄãµÄËØÄŞ½£·¨ĞŞÎª²»¹»£¬ÎŞ·¨ĞŞÁ¶¡£\n");
}		
        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("ÄãµÄÌåÁ¦²»¹»ÎŞ·¨Á·Ï°¡£\n");
	       if ((int)me->query_skill("taixuan-gong", 1) < 100)
                return notify_fail("ÄãµÄÌ«ĞşÉñ¹¦»ğºòÌ«Ç³¡£\n");
 	if(me->query_skill("xiuli-qiankun", 1) < 250)
		return notify_fail("ÄãµÄĞäÀïÇ¬À¤ĞŞÎª²»¹»£¬ÎŞ·¨ĞŞÁ¶¡£\n");

	if(me->query_skill("wuyu-quan", 1) < 250)
		return notify_fail("ÄãµÄÎåÓüÈ­ĞŞÎª²»¹»£¬ÎŞ·¨ĞŞÁ¶¡£\n");

	if(me->query_skill("sata-shenfa", 1) < 250)
		return notify_fail("ÄãµÄìªí³Éí·¨ĞŞÎª²»¹»£¬ÎŞ·¨ĞŞÁ¶¡£\n");

		
if (me->query_skill("huanhe-dao", 1) > 251)
{
			if(me->query_skill("sumi-jian", 1) < me->query_skill("huanhe-dao", 1))
		return notify_fail("ÄãµÄËØÄŞ½£·¨ĞŞÎª²»¹»£¬ÎŞ·¨ĞŞÁ¶¡£\n");
}		
        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("Äã¾õµÃìÓºÕµ¶Éî°ÂÖ®¼«£¬Ò»Ê±¼äÄÑÒÔÁì»á¡£\n");

	
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string func)
{
	return __DIR__"huanhe-dao/"+func;
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int level, jiali, time,level2;
int i, ap, dpp, dpd, dpf,lvl;
	object weapon,weapon2;
	string type, msg;
	weapon = me->query_temp("weapon");
lvl = me->query_skill("taixuan-gong", 1);
        if (random(me->query_skill("taixuan-gong",1)) < 60 ||		             me->query_skill("force",1) < 100 )
        return 0;


if (me->query_skill_mapped("force") != "taixuan-gong")
return 0;
if (me->query("neili") < 500)
return 0;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return 0;

        if ((int)me->query_skill("literate", 1)> 5 )	
return 0;
	jiali = me->query("jiali");

if (!jiali) jiali=90;
	if( damage_bonus > 20 && random(me->query_skill("taixuan-gong",1))>120 
	) {
	victim->receive_wound("qi", (random(jiali)+80));
return random(2) ? HIW "$N" HIW "Ò»ÕĞ¹¥³ö£¬¾¹¾íÆğÇ§²ãÆøÀË£¬Ì«ĞşÄÚ¾¢"
                                   "¶ÙÊ±Ô´Ô´²»¾øÓ¿Èë$n" HIW "ÌåÄÚ£¡\n" NOR:
                                   HIW "$N" HIW "Ì«ĞşÄÚ¾¢±Å·¢£¬$n" HIW "Ö»¸ĞÈ«ÉíÒ»"
                                   "Õğ£¬µÇÊ±¡°¿¦¿¦¿¦¡±¶ÏÁËÊı¸ùÀß¹Ç£¡\n" NOR;
}
}