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
	set_name("[33m½ğ¹âÖ®½£[2;37;0m", ({ "jinguang sword", "sword" }));
	set_weight(4061);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[33m½ğ¹âÖ®½£[2;37;0mÕâÊÇÒ»°ÑÓÉÊ®·Ö¼áÓ²µÄ[1;33m½ğÌú[2;37;0mÖÆ³É£¬ÖØ°Ë½ïÒ»Á½¶şÇ®µÄ[33m½ğ¹âÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´Ê®·Ö·æÀû£¬¾ßÓĞ[1;34mÒĞÌìÍÀÁú[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[35m±ê×¼[2;37;0m [33mÍÁ[2;37;0m:[33mºÜ¸ß[2;37;0m [1;35m·ç[2;37;0m:[33mºÜ¸ß[2;37;0m 
[1;37mÀ×[2;37;0m:[33mºÜ¸ß[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31mÎŞË«[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
ÌåÁé:[32m´Ö²Ú[2;37;0m ×ÏÊ¯:[35m±ê×¼[2;37;0m ÖÜÌì:[36m²»´í[2;37;0m ÍşÁ¦:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mĞ¡Âí[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÈ­·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xiaoma");
		set("ownername", "Ğ¡Âí");
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 50);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 16);
    set("weapon_prop/defense", 36);
    
    set("weapon_prop/neili", 18);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 36);

    set("wtypeA",0);
    set("wtypeB",5);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",4);
    set("wtypeF",4);
    set("wtypeG",4);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 12);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(711);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";