// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit BLADE;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[1;31mÉ±Öíµ¶[2;37;0m", ({ "moye blade", "blade" }));
	set_weight(5489);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "±ú");
		set("long", @LONG
[31mÄªĞ°·æÀûÎŞ±È£¬ÄÜ¿ªÌì±ÙµØ£¬µ´Ñı³ıÄ§£¡
[2;37;0mÕâÊÇÒ»±úÓÉ¾ø¶Ô¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0mÖÆ³É£¬ÖØÊ®½ï¾ÅÁ½ÆßÇ®µÄ[31mÄªĞ°Ö®µ¶[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´¾ø¶Ô·æÀû£¬¾ßÓĞ[1;35m¾øÊÀº±¼û[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[40mµØ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [36mÄ¾[2;37;0m:[1;31m´´ÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;35m¾øÊÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;34mµç[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÁé:[32m´Ö²Ú[2;37;0m ÌåÁé:[35m±ê×¼[2;37;0m °×Ê¯:[1;34m¾ÙÊÀ[2;37;0m ×ÏÊ¯:[35m±ê×¼[2;37;0m ³¤Éú:[35m±ê×¼[2;37;0m ÍşÁ¦:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m°¢±¦[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m½£·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "apo");
		set("ownername", "°¢±¦");
		set("value", 36000);
		set("weapon_prop/intelligence",36);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 82);
    set("weapon_prop/parry", 51);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 55);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 52);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 59);

    set("wtypeA",0);
    set("wtypeB",14);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",11);
    set("wtypeG",6);
    set("wtypeH",10);
    set("wtypeI",0);
    set("wtypeJ",14);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 23);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_blade(944);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";