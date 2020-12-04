#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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
	      set_name("[1;31mÄ«¼£[2;37;0m", ({ "lianyu hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸±");
		set("long", @LONG
[1;31mÈıÊ®ÈıÌìÏÂÓĞµØ£¬µØÏÂÓĞ³Ç£¬³ÇÃû¹í³Ç£¬´óĞ¡ÑıÄ§£¬ÈËÉñĞóÉú¶¼ÔÚ´ËÂÖ»ØÍù·µ£¬Î½Ö®¡°Á¶Óü¡±£¡
[2;37;0mÕâÊÇÒ»¸±ÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[37mÌì²ÏË¿[2;37;0mÖÆ³É£¬ÖØÈı½ïÒ»Á½¶şÇ®µÄ[1;31mÁ¶ÓüÖ®ÊÖÌ×[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;31mÄ§[2;37;0m:[35m±ê×¼[2;37;0m [32mË®[2;37;0m:[1;31mÎŞË«[2;37;0m [31m»ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;31m¿ªÔª[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ¾ø´ú:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
°×Ê¯:[31m¾«ÖÂ[2;37;0m ×ÏÊ¯:[31m¾«ÖÂ[2;37;0m ÖÜÌì:[35m±ê×¼[2;37;0m ³¤Éú:[1;36mÍêÃÀ[2;37;0m ÍşÁ¦:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m»¨ÎŞÀâ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕĞ¼Ü[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "enjoy");
		set("ownername", "»¨ÎŞÀâ");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",32);
		set("armor_prop/karey",56);
		set("armor_prop/percao",32);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",64);
    set("armor_prop/dodge", 65);
    set("armor_prop/parry", 66);
    set("armor_prop/attack", 32);


    set("armor_prop/armor", 1353);
    set("armor_prop/defense", 64);
    
    set("armor_prop/neili", 57);
    set("armor_prop/qi", 72);
    set("armor_prop/jing", 64);
    set("armor_prop/jingli", 56);
    set("armor_prop/damage", 1693);

    set("wtypeA",7);
    set("wtypeB",8);
    set("wtypeC",12);
    set("wtypeD",8);
    set("wtypeE",8);
    set("wtypeF",13);
    set("wtypeG",4);
    set("wtypeH",6);
    set("wtypeI",8);
    set("wtypeJ",7);
    set("wtypeK",8);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 20);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";