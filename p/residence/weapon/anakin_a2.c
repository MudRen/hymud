#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;33m¾øµØÖ®¶Ü[2;37;0m", ({ "taie shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ãæ");
		set("long", @LONG
[31mÌ«°¢µÛÍõÖ®±ø£¬³ÖÖ®ÄÜºÅÁîÌìÏÂ£¬ÄªÓĞ²»´Ó£¡
[2;37;0mÕâÊÇÒ»ÃæÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0m¼ÓÉÏ[1;33mÁú¼ë²ÏË¿[2;37;0mÖÆ³É£¬ÖØËÄ½ïÒ»Á½°ËÇ®µÄ[31mÌ«°¢Ö®¶Ü[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[31m»ğ[2;37;0m:[1;31m»ÙÌì[2;37;0m [33mÍÁ[2;37;0m:[1;31m»ÙÌì[2;37;0m [1;35m·ç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;34mµç[2;37;0m:[1;31m¿ªÔª[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[31m¾«ÖÂ[2;37;0m 
ÌåÁé:[1;36mÍêÃÀ[2;37;0m ÉÁµç:[32m´Ö²Ú[2;37;0m 
³¤Éú:[1;34m¾ÙÊÀ[2;37;0m ²»ÀÏ:[1;36mÍêÃÀ[2;37;0m ÍşÁ¦:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m°²ÄÉ½ğ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÆ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "anakin");
		set("ownername", "°²ÄÉ½ğ");
		set("value", 36000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 72);


    set("armor_prop/armor", 925);
    set("armor_prop/defense", 70);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 84);
    set("armor_prop/jing", 76);
    set("armor_prop/jingli", 76);
    set("armor_prop/damage", 616);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",15);
    set("wtypeE",15);
    set("wtypeF",7);
    set("wtypeG",6);
    set("wtypeH",13);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";