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
	set_name("[31m¾ŞãÚÖ®½£[2;37;0m", ({ "juque sword", "sword" }));
	set_weight(7953);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[31m¾ŞãÚ¼áÓ²ÎŞ±È£¬ÄÜ¿ªÌì±ÙµØ£¬µ´Ñı³ıÄ§£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉ¼«Îª¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0mÖÆ³É£¬ÖØÊ®Îå½ï¾ÅÁ½ÁãÇ®µÄ[31m¾ŞãÚÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´¼«Îª·æÀû£¬¾ßÓĞ[1;31m¿ªÔª´´ÊÀ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;31mÄ§[2;37;0m:[31m¾«ÖÂ[2;37;0m [36mÄ¾[2;37;0m:[1;32mÄ§Íõ[2;37;0m [32mË®[2;37;0m:[1;33mÃğÊÀ[2;37;0m [31m»ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;31mÎŞË«[2;37;0m [1;35m·ç[2;37;0m:[1;33mÃğÊÀ[2;37;0m 
[1;34mµç[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÁé:[32m´Ö²Ú[2;37;0m ÌìĞş:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
ÌåÁé:[33mºÜ¸ß[2;37;0m ×ÏÊ¯:[1;36mÍêÃÀ[2;37;0m ÖÜÌì:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¾²ÎÄ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m°µÆ÷[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kamuls");
		set("ownername", "¾²ÎÄ");
		set("value", 36000);
		set("weapon_prop/intelligence",38);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",36);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 72);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 46);
    set("weapon_prop/defense", 43);
    
    set("weapon_prop/neili", 49);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",16);
    set("wtypeD",8);
    set("wtypeE",12);
    set("wtypeF",16);
    set("wtypeG",0);
    set("wtypeH",12);
    set("wtypeI",11);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    

                set("skill", ([
                        "name": "throwing",
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
	
	init_sword(1347);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";