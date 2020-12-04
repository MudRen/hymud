// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

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
	set_name("[35m¶¾Áú½£[2;37;0m", ({ "yuchang sword", "sword" }));
	set_weight(7032);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[31mÓã³¦ÇáÇÉÎŞ±È£¬ÄÜ¿ªÌì±ÙµØ£¬µ´Ñı³ıÄ§£¡
[2;37;0mÕâÊÇÒ»¸ùÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0mÖÆ³É£¬ÖØÊ®ËÄ½ïÁãÁ½ÁùÇ®µÄ[31mÓã³¦Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;35m¾øÊÀº±¼û[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;31mÄ§[2;37;0m:[1;31m»ÙÌì[2;37;0m [1;33m½ğ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [36mÄ¾[2;37;0m:[1;31mÎŞË«[2;37;0m [32mË®[2;37;0m:[1;31m´´ÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÁé:[33mºÜ¸ß[2;37;0m ÌìÔ¨:[33mºÜ¸ß[2;37;0m °×Ê¯:[33mºÜ¸ß[2;37;0m ×ÏÊ¯:[1;34m¾ÙÊÀ[2;37;0m ÖÜÌì:[35m±ê×¼[2;37;0m ³¤Éú:[33mºÜ¸ß[2;37;0m ²»ÀÏ:[1;34m¾ÙÊÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mçóçì»ì»ì[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÄÚ¹¦[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "eddie");
		set("ownername", "çóçì»ì»ì");
		set("value", 36000);
		set("weapon_prop/intelligence",46);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",46);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 46);
    set("weapon_prop/parry", 86);
    set("weapon_prop/attack", 72);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 50);
    set("weapon_prop/qi", 72);
    set("weapon_prop/jing", 80);
    set("weapon_prop/jingli", 80);
    set("weapon_prop/damage", 0);

    set("wtypeA",10);
    set("wtypeB",12);
    set("wtypeC",14);
    set("wtypeD",9);
    set("wtypeE",12);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",15);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 26);

		set("wield_msg", "$N½«$nÄÃÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(932);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";